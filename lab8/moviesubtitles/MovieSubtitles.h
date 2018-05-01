//
// Created by pawelgalka on 25.04.18.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <string>
#include <exception>
#include <memory>
#include <stdexcept>
#include <regex>

namespace moviesubs{
    class MovieSubtitles {
    public:
        MovieSubtitles();
        virtual ~MovieSubtitles();
        virtual void ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *instream, std::stringstream *outstream) =0;
    };

    class SubRipSubtitles : public MovieSubtitles{
    public:
        SubRipSubtitles();
        virtual ~SubRipSubtitles();
        virtual void ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *instream, std::stringstream *outstream) override ;
    };

    class MicroDvdSubtitles : public MovieSubtitles{
    public:
        MicroDvdSubtitles();
        virtual ~MicroDvdSubtitles();
        virtual void ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *instream, std::stringstream *outstream) override ;
    };

    class SubtitlesException : public std::invalid_argument{
    public:
        SubtitlesException(int line, const std::string &message) : invalid_argument(message) {};
    };

    class NegativeFrameAfterShift : public SubtitlesException{
    public:
        NegativeFrameAfterShift(int line, const std::string &message) : SubtitlesException(line,"Invalid framerate"){};
    };

    class SubtitleEndBeforeStart : public SubtitlesException{
    public:
        SubtitleEndBeforeStart(int line_num, std::string line) : SubtitlesException(line_num,"At line "+std::to_string(line_num)+": "+line), line_{line_num} {};
        int LineAt() const ;

    private:
        int line_;
    };

    class InvalidSubtitleLineFormat : public SubtitlesException{
    public:
        InvalidSubtitleLineFormat(int line_num, const std::string &message) : SubtitlesException(line_num,message), line_{line_num} {};
        int LineAt() const ;

    private:
        int line_;
    };

    class MissingTimeSpecification : public SubtitlesException{
    public:
        MissingTimeSpecification(int line, const std::string &message) : SubtitlesException(line, "Missing Time Specification") {};
    };

    class OutOfOrderFrames : public SubtitlesException{
    public:
        OutOfOrderFrames(int line, const std::string &message) : SubtitlesException(line, "Out Of Order Frames") {};
    };
}



#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
