#ifndef ARTICLEPARSER_H
#define ARTICLEPARSER_H

#include <string>

using std::string;

class ArticleParser
{
    public:
        ArticleParser();
        ~ArticleParser();

        // Singleton
        static ArticleParser* get_instance();

        size_t get_length(const string& s);
        void strip_punct(string& s);
        void strip_tag_content(string& s, const string& openTag, const string& closeTag);
        int std_string_find(const string& s, const string& toFind);
        int c_string_find(const char* s, const char* toFind);
        int c_string_find2( char* s,  char* toFind);

    private:
        static ArticleParser* p;

};

#endif // ARTICLEPARSER_H
