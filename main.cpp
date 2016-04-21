#include <iostream>
#include "ArticleParser.h"
#include <string>
#include <fstream>

using namespace std;

string read_file(const string& path)
{
    ifstream fin(path);
    if (!fin) return "";
    string s;
    fin.seekg(0, ios::end);
    s.resize(fin.tellg());
    fin.seekg(0, ios::beg);
    fin.read(&s[0], s.size());
    return s;
}



int main()
{
    ArticleParser* p = ArticleParser::get_instance();
    string path = "/media/preciseedu/D/enwiki-20150205-pages-meta-current3.xml-p000025001p000055000";
    //string path = "/home/preciseedu/Desktop/test.txt";
    string s = read_file(path)/ 0.162s
    //string s = "Hello, fuck you bitch! yo";
    //
    //cout << p->std_string_find(s, "are");  // 0.652s





    //

    //cout << p->c_string_find2(s.c_str(), "fungisnice") << endl; // 0.710s

    cout << p->c_string_find2(s.c_str(), "are") << endl;  // 0.710s


    return 0;
}

/**Status.
//Config.
//Thread.
//Network.
//Mapping
//Logging.
//Interface.

//Wed  Mapping
//Th   Network, Interface.
//Fri  Thread, Status
//Sat  Logging.
//Sun  Final Nice.
*/

/** Streaming/Audio stuff for lux. */
/** Spelling Check, Grammar Check  [give your code to Lux] * <TMR> */


/** Vocab */
/** Essay Grader */


