// #include <stdio.h>
// #include "strList.h"
// 
// void main() {
// 	StrList strList;
// 	strList.push_front("Main");
// 	strList.print();
// 	strList.push_back("List");
// 	strList.print();
// 	strList.push_front("gT");
// 
// 	printf("%d\n",strList.size());
// 
// 	
// 	strList.print();
// 
// 	strList.pop_front();
// 	strList.pop_back();
// 	strList.print();
// }

#include <stdio.h>
#include "file.h"

void main() {
	FileList file;

	file.push_back("world");
	file.push_front("hello ");
// 	file.print();
	file.save("a.txt");	
}
