#include "ArticleParser.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

ArticleParser::ArticleParser()
{
    //ctor
}

ArticleParser::~ArticleParser()
{
    //dtor
}

void ArticleParser::init(const string& content)
{
    _content = content;
}

void ArticleParser::print() const
{
    cout << _content;
}
