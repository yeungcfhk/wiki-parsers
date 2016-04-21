#include "XMLController.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;

XMLController::XMLController()
{
    //ctor
}

XMLController::~XMLController()
{
    //dtor
}

/*
Counts the number of <page> tag.

Assumptions:
- <page> would be accompanied by a </page> tag before the next <page> tag
- each <page> tag is in a separate line on its own
*/

int XMLController::get_num_articles()
{
    int cnt = 0;
    std::ifstream fin(_path);
    if (!fin)
    {
        cout << "cannot open file" << endl;
        return 0;
    }
    string line;
    while (getline(fin, line))
    {
        if (line.find("<page>") != string::npos)
        {
            ++cnt;
        }
    }
    return cnt;
}


/*
Stores the articles into the private vector of the class.

Assumptions:
- every <page> or </page> is in its own line
- no nesting of pages, i.e. a <page> tag must be followed by a </page> tag

*/
void XMLController::store_articles()
{
    std::ifstream fin(_path);
    if (!fin)
    {
        cout << "cannot open file" << endl;
    }
    string line;
    size_t articleCnt = 0;
    size_t numBytes = 0;
    size_t startPos, endPos;
    bool started = false;
    while (getline(fin, line))
    {
        if (!started)  // if not yet found a <page> tag
        {
            startPos = line.find("<page>");
            if (startPos != string::npos)
            {
                startPos += fin.tellg() - line.length() - 1;  // points to starting of <page>, -1 because of the newline character
                started = true;
            }
        }
        else  // found a <page> tag, so now we need to find a </page> tag
        {
            endPos = line.find("</page>");
            if (endPos != string::npos)
            {
                size_t curPos = fin.tellg();
                string page;
                fin.seekg(startPos, std::ios::beg);
                page.resize(curPos-startPos);  // plus the </page> tag length
                fin.read(&page[0], page.size());
                _articles.push_back(page);
                ++articleCnt;
                cout << articleCnt << endl;
                cout << page;
                getchar();
                numBytes += page.length();
                started = false;
            }
        }
    }
    cout << "Total number of articles: " << _articles.size() << endl;
    cout << "Total number of bytes: " << numBytes << endl;
}
