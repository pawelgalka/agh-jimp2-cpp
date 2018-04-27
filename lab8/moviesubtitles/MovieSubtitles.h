//
// Created by pawelgalka on 25.04.18.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <string>
#include <exception>
#include <memory>
#include <stdexcept>

namespace moviesubs{
    class MovieSubtitles {
    public:
        MovieSubtitles();
        virtual ~MovieSubtitles();
        virtual void ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *instream, std::stringstream *outstream);
    };

    class SubRipSubtitles : public MovieSubtitles{

    };

    class MicroDvdSubtitles : public MovieSubtitles{

    };
}



#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
