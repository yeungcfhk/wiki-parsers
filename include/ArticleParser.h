#ifndef ARTICLEPARSER_H
#define ARTICLEPARSER_H

#include <string>

using std::string;

class ArticleParser
{
    public:
        ArticleParser();
        ~ArticleParser();

        void init(const string& content);
        void print() const;
    private:
        string _content;
};

#endif // ARTICLEPARSER_H
