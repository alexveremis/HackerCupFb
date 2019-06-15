#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
int i=0,j=0,argrammwn,batraxoi=0;
char c;
ifstream fp;
fp.open(argv[1]);
fp >>argrammwn;
fp.get(c);
//cout<<argrammwn<<c;
char apantiseis[argrammwn];
bool flag=false;
 while (fp.get(c)) {
	if (c=='.') {
		flag=true;
		j--;}
        else if (c=='\n') {
		if ((j-1>=0 || batraxoi-1>1)&& flag==true)apantiseis[i]='Y';
		else apantiseis[i]='N';
		i++;
		flag =false;
		j=0;
		batraxoi=0;
			}
	else {
		j++;
		batraxoi++;}
    }

fp.close();

ofstream myfile;
myfile.open ("output.txt");
 for(i = 0; i< argrammwn; i++){
    myfile<<"Case #"<<i+1<<": " << apantiseis[i]<<'\n';
    }
 myfile.close();
 return 0;
}
