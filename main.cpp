#include <iostream>
#include "ArticleParser.h"

using namespace std;

int main()
{
    ArticleParser ap;
    ap.init("Hello world!");
    ap.print();
    return 0;
}
