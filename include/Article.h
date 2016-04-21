#ifndef ARTICLE_H
#define ARTICLE_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Article
{
    public:
        Article();
        Article(const string& s);
        ~Article();

        // Getters and setters
        string get_title() const { return _title; }
        string get_content() const { return _content; }
        vector<string> get_categories() const { return _categories; }
        void set_title(const string& title) { _title = title; }
        void set_content(const string& content) { _content = content; }
        void set_categories(const vector<string>& categories) { _categories = categories; }

    private:
        string _title;
        string _content;
        vector<string> _categories;
};

#endif // ARTICLE_H
