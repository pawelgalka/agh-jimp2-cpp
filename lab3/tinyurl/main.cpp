//
// Created by pawel on 14.03.18.
//

#include "TinyUrl.h"
using namespace tinyurl;

int main(){
    //std::cout<<"X";


    //nowy.Code = {'0','1','2','3','4','5'};

    std::unique_ptr<TinyUrlCodec> state = Init();
    /*for (auto const &value : state->CurrentState){
        std::cout << value;
    }*/
    //std::string url = "https://google.com", url1 = "https://wikipedia.org", url2="https://reviewable.io/";
    //const auto hash = tinyurl::Encode(url, &state);
    //auto decoded_url = tinyurl::Decode(state, hash);
   // if (Decode(state,Encode(url,&state))==url) std::cout << "XD";
    //std::cout<< hash << std::endl;
    //std::cout<< decoded_url ;
    //std::unique_ptr<TinyUrlCodec> state1 = Init();
    //std::cout <<
    std::vector<std::string> tinyUrlBunchOfUrlsTestData
            {"https://google.com", "https://wikipedia.org", "https://regex101.com/",
             "http://www.regular-expressions.info/recurse.html#balanced", "https://xkcd.com/1755/", "https://xkcd.com/1758/",
             "https://xkcd.com/1775/", "http://stackoverflow.com/questions/29397066/c-regexp-to-parsing-nested-struct",
             "http://www.regular-expressions.info/boost.html",
             "https://phys.org/news/2016-09-discovery-quasars-ancient-universe.html",
             "https://phys.org/news/2017-03-discovery-bevy-quasars-boost-efforts.html",
             "https://www.youtube.com/watch?v=FkCT_LV9Syk", "http://ai.ia.agh.edu.pl/wiki/pl:dydaktyka:jimp2:2017:labs:pamiec2",
             "https://leetcode.com/problemset/algorithms/#", "https://en.wikipedia.org/wiki/List_of_Unicode_characters",
             "http://unicode.org/reports/tr15/", "https://reviewable.io/", "https://github.com/integrations",
             "https://github.com/integrations/travis-ci", "https://github.com/integrations/sonarqube",
             "http://www.talkenglish.com/vocabulary/top-2000-vocabulary.aspx", "https://www.topcoder.com",
             "https://pl.wikipedia.org/wiki/Filtr_Kalmana", "https://www.youtube.com/watch?v=2pzxEmh0gYw",
             "http://geofl.ge/#!/page_saxelmdzvanelo", "https://www.youtube.com/watch?v=K83YZYcpExc",
             "https://www.memrise.com/", "https://www.duolingo.com/"
            };
    for (auto value : tinyUrlBunchOfUrlsTestData) {
        auto hash = tinyurl::Encode(value, &state);
        auto decoded_url = tinyurl::Decode(state, hash);
        if (value == decoded_url) std::cout << hash << std::endl;
    }
    return 0;
}