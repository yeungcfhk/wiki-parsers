#ifndef XMLCONTROLLER_H
#define XMLCONTROLLER_H

#include "ArticleParser.h"
#include "Article.h"

class XMLController
{
    public:
        XMLController();
        ~XMLController();

        // Getters and setters
        string get_path() const { return _path; }
        void set_path(const string& path) { _path = path; }

        // Reads the file and returns the number of articles (defined by number of <page> tags)
        int get_num_articles();

        // Stores the articles into a vector
        void store_articles();
    private:
        string _path;
        vector<Article> _articles;
};

#endif // XMLCONTROLLER_H
