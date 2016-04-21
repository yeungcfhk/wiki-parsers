#include "ArticleParser.h"
#include <algorithm>
#include <cstring>


char* my_strstr(char *haystack, const char *needle) {
    if (haystack == NULL || needle == NULL) {
        return NULL;
    }

    for ( ; *haystack; haystack++) {
        // Is the needle at this point in the haystack?
        const char *h, *n;
        for (h = haystack, n = needle; *h && *n && (*h == *n); ++h, ++n) {
            // Match is progressing
        }
        if (*n == '\0') {
            // Found match!
            return haystack;
        }
        // Didn't match here.  Try again further along haystack.
    }
    return NULL;
}

ArticleParser::ArticleParser()
{
    //ctor
}

ArticleParser::~ArticleParser()
{
    //dtor
}

ArticleParser* ArticleParser::p = nullptr;

ArticleParser* ArticleParser::get_instance()
{
    if (!p)
    {
        p = new ArticleParser;
    }
    return p;
}

size_t ArticleParser::get_length(const string& s)
{
    return s.length();
}

void ArticleParser::strip_punct(string& s)
{
    s.erase(std::remove_if(s.begin(), s.end(), ispunct), s.end());
}

void ArticleParser::strip_tag_content(string& s, const string& openTag, const string& closeTag)
{
    size_t curPos = 0, startPos = 0, endPos = 0;
    bool started = false;
    int levelCnt = 0;  // count the level of the tag if it is nested
    while (true)
    {
        // First of all, we try to find the openTag.
        // Once it is found, we try to look for both open and close tags, meanwhile counting the level (due to possible nested tags).
        // When the count reaches 0, that means we have found matched open and close tag(s),
        // therefore we can safely erase anything in between
        if (!started)
        {
            curPos = s.find(openTag, curPos);
            if (curPos == string::npos)
                break;
            // if found the openTag, increment the level count
            ++levelCnt;
            started = true;
            startPos = curPos;  // stores the starting position for erasing
            curPos += openTag.length();
        }
        else
        {
            curPos = s.find(closeTag, curPos);
            if (curPos == string::npos)  // if cannot find closeTag, it is a file syntax error
                break;
            // Found the closeTag, decrement the level count
            --levelCnt;
            started = false;
            endPos = curPos + closeTag.length();
            if (levelCnt == 0)  // level reaches 0, which means we can start the erase process
            {
                s.erase(startPos, endPos - startPos);
            }
            // After erasing, the curPos should be set to the position right after the erased text
            curPos = startPos;
        }
    }
}

int ArticleParser::std_string_find(const string& s, const string& toFind)
{
    int cnt = 0;
    size_t pos = 0;
    while (true)
    {
        pos = s.find(toFind, pos);
        if (pos == string::npos)
            break;
        ++cnt;
        ++pos;
    }
    return cnt;
}

int ArticleParser::c_string_find(const char* s, const char* toFind)
{
    int cnt = 0;
    size_t s_sz = strlen(s);
    size_t find_sz = strlen(toFind);
    for (int i=0; i<s_sz; ++i)
    {
        bool match = true;
        for (int j=0; j<find_sz; ++j)
        {
            if (s[i+j] != toFind[j])
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            ++cnt;
            i+=find_sz;
        }
    }
    return cnt;
}

int ArticleParser::c_string_find2( char* a,  char* b)
{
    size_t cnt = 0;

    while(true)
    {
        char * new_pos = my_strstr(a,b);
        if(new_pos!=nullptr)
        {
            cnt++;
            a = new_pos + 1;
        }
        else
        {
            break;
        }

    }


    return cnt;
}
