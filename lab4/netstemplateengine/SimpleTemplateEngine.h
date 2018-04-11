//
// Created by pawel on 21.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>

namespace nets{
    class View {
    public:
        View();
        View(std::string string_input);
        ~View();

        std::string Render(const std::unordered_map <std::string, std::string> &model) const;
        
        std::string Output() const ;

    private:
        std::string input_;
    };
}



#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
