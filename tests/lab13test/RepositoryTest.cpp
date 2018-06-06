//
// Created by galkpawe on 06.06.18.
//

#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include <functional>
#include <experimental/optional>

class Repository {
public:
    virtual std::experimental::optional<int> FindById(int id)=0;


};

class EmptyRepository : public Repository{
public:
    std::experimental::optional<int> FindById(int id) override {
        return std::experimental::optional<int>();
    }

};

class FullRepository : public Repository{
public:
    std::experimental::optional<int> FindById(int id) override {
        return 37;
    }
    std::map<int,int> mapa{{1,1}};
};



class Controller{
public:
    Controller(std::unique_ptr<Repository> arg):repo{std::move(arg)} {};
    int Find(int id){
        if (repo->FindById(1)== std::experimental::optional<int>() ){
            return 404;
        }
        else return 200;
    }

private:
    std::unique_ptr<Repository> repo;
};

TEST(RepositoryTest, TestEmpty) {
    std::unique_ptr<Repository> repo = std::make_unique<EmptyRepository>();
    Controller controller(std::move(repo));
    EXPECT_EQ(404,controller.Find(1));
}

TEST(RepositoryTest, TestFull) {
    std::unique_ptr<Repository> repo = std::make_unique<FullRepository>();
    Controller controller(std::move(repo));
    EXPECT_EQ(200,controller.Find(1));
}
