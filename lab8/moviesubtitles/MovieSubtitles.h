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

    class MovieSubtitlesError : public std::invalid_argument{
    public:
        MovieSubtitlesError(const std::string &message) : invalid_argument(message) {};
    };

    class NegativeFrameAfterShift : public MovieSubtitlesError{
    public:
        NegativeFrameAfterShift() : MovieSubtitlesError("Invalid framerate"){};
    };

    class SubtitleEndBeforeStart : public MovieSubtitlesError{
    public:
        SubtitleEndBeforeStart(int line_num, std::string line) : MovieSubtitlesError("At line "+std::to_string(line_num)+": "+line), line_{line_num} {};
        int LineAt() const ;

    private:
        int line_;
    };

    class InvalidSubtitleLineFormat : public MovieSubtitlesError{
    public:
        InvalidSubtitleLineFormat(int line_num) : MovieSubtitlesError(std::to_string(line_num)), line_{line_num} {};
        int LineAt() const ;

    private:
        int line_;
    };

    class MissingTimeSpecification : public MovieSubtitlesError{
    public:
        MissingTimeSpecification() : MovieSubtitlesError("Missing Time Specification") {};
    };

    class OutOfOrderFrames : public MovieSubtitlesError{
    public:
        OutOfOrderFrames() : MovieSubtitlesError("Out Of Order Frames") {};
    };
}



#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
