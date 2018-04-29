//
// Created by pawelgalka on 25.04.18.
//

#include <iostream>
#include <zconf.h>
#include "MovieSubtitles.h"

namespace moviesubs{
    MicroDvdSubtitles::MicroDvdSubtitles() {

    }

    MicroDvdSubtitles::~MicroDvdSubtitles() {

    }
    
    MovieSubtitles::MovieSubtitles() {

    }

    MovieSubtitles::~MovieSubtitles() {

    }

    SubRipSubtitles::SubRipSubtitles() {

    }

    SubRipSubtitles::~SubRipSubtitles() {

    }
    
    void SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *instream,
                                              std::stringstream *outstream) {
        if (fps <= 0){
            throw NegativeFrameAfterShift();
        }
        if (instream->str().empty()) throw std::invalid_argument{"Invalid argument"};
        int shift = delay*fps/1000;
        std::regex pattern{"(([0-9]+)\n(([0-9]{2,}):([0-9]{2}):([0-9]{2}),([0-9]{3}) --> ([0-9]{2,}):([0-9]{2}):([0-9]{2}),([0-9]{3}))((\n.*)+[\n]{1,2}))"}, line_pattern{".*\n.*\n(.*\n)+\n?[^0-9]"};
        std::string input = instream->str(), line = "", out ="";
        int line_num=0;
        while (!input.empty()){
            size_t pos = input.find("\n\n");
            if (pos > input.length()) pos=input.length()-2;
            line = input.substr(0,pos+2);
            input = input.substr(pos+2,input.length());
            out ="";
            line_num++;
            std::smatch result;
            if(!std::regex_match(line,result,pattern)){
                throw InvalidSubtitleLineFormat(line_num);
            }
            if (result[2].str()!=std::to_string(line_num)) throw OutOfOrderFrames();
            int appear_time,disappear_time,appear_delayed,disappear_delayed;
            appear_time = 3600000*std::stoi(result[4].str())+60000*std::stoi(result[5].str())+1000*std::stoi(result[6].str())+std::stoi(result[7].str());
            disappear_time= 3600000*std::stoi(result[8].str())+60000*std::stoi(result[9].str())+1000*std::stoi(result[10].str())+std::stoi(result[11].str());
            if (appear_time>disappear_time) throw SubtitleEndBeforeStart(line_num,result[3].str());

            appear_delayed=appear_time+delay;
            disappear_delayed=disappear_time+delay;
            if (appear_delayed<0) throw  NegativeFrameAfterShift();
            if (std::to_string(appear_delayed/3600000).length()<2){
                out += result[2].str()+"\n0"+std::to_string(appear_delayed/3600000)+":";
            }
            else{
                out += result[2].str()+"\n"+std::to_string(appear_delayed/3600000)+":";
            }
            appear_delayed-=3600000*(appear_delayed/3600000);
            if (std::to_string(appear_delayed/60000).length()<2){
                out += "0"+std::to_string(appear_delayed/60000)+":";
            }
            else{
                out += std::to_string(appear_delayed/60000)+":";
            }
            appear_delayed-=60000*(appear_delayed/60000);
            if (std::to_string(appear_delayed/1000).length()<2){
                out += "0"+std::to_string(appear_delayed/1000)+",";
            }
            else{
                out += std::to_string(appear_delayed/1000)+",";

            }
            appear_delayed-=1000*(appear_delayed/1000);
            if (std::to_string(appear_delayed).length()<3){
                if (std::to_string(appear_delayed).length()<2)
                    out += "00"+std::to_string(appear_delayed);
                else
                    out += "0"+std::to_string(appear_delayed);
            }
            else{
                out += std::to_string(appear_delayed);
            }
            out += " --> ";
            if (std::to_string(disappear_delayed/3600000).length()<2){
                out += "0"+std::to_string(disappear_delayed/3600000)+":";
            }
            else{
                out += "\n"+std::to_string(disappear_delayed/3600000)+":";
            }
            disappear_delayed-=3600000*(disappear_delayed/3600000);
            if (std::to_string(disappear_delayed/60000).length()<2){
                out += "0"+std::to_string(disappear_delayed/60000)+":";
            }
            else{
                out += std::to_string(disappear_delayed/60000)+":";
            }
            disappear_delayed-=60000*(disappear_delayed/60000);
            if (std::to_string(disappear_delayed/1000).length()<2){
                out += "0"+std::to_string(disappear_delayed/1000)+",";
            }
            else{
                out += std::to_string(disappear_delayed/1000)+",";

            }
            disappear_delayed-=1000*(disappear_delayed/1000);
            if (std::to_string(disappear_delayed).length()<3){
                if (std::to_string(disappear_delayed).length()<2)
                    out += "00"+std::to_string(disappear_delayed);
                else
                    out += "0"+std::to_string(disappear_delayed);
            }
            else {
                out += std::to_string(disappear_delayed);
            }
            out+=result[12].str();
            *outstream << out.c_str();
        }
    }

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *instream,
                                                std::stringstream *outstream) {
        if (fps <= 0){
            throw NegativeFrameAfterShift();
        }
        if (instream->str().empty()) throw std::invalid_argument{"Invalid argument"};
        int shift = delay*fps/1000;
        std::regex pattern{"(\\{([0-9]+)\\}\\{([0-9]+)\\})"}, line_pattern{".*\n?"};
        std::string input = instream->str(), line = "",out="";
        int line_num = 0;
        while (!input.empty()){
            line_num++;
            std::smatch result,result1;
            std::regex_search(input,result1,line_pattern);
            line=result1.str();
            input=result1.suffix();
            if (!std::regex_search(line,result,pattern)){
                throw InvalidSubtitleLineFormat(line_num);
            }
            if (std::stoi(result[2].str())+shift<0) throw NegativeFrameAfterShift();
            if (std::stoi(result[2].str())>std::stoi(result[3].str())) throw SubtitleEndBeforeStart(line_num,line.substr(0,line.length()-1));
            out+= "{"+std::to_string(std::stoi(result[2].str())+shift)+"}"+"{"+std::to_string(std::stoi(result[3].str())+shift)+"}"+result.suffix().str();
        }
        *outstream << out.c_str();
    }

    int InvalidSubtitleLineFormat::LineAt() const {
        return line_;
    }

    int SubtitleEndBeforeStart::LineAt() const {
        return line_;
    }
}