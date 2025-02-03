#include <iostream>
#include<cstring>
using namespace std;
class cwh{
    protected:
    string title;
    float rating;
    public:
    cwh(string s, float r)
    {title = s;
    rating =r;
    }
    virtual void display()
    {}
};
class video:public cwh{
    float vidlength;
    public:
    video(string s, float r, float vl):cwh(s,r)
    {
        vidlength=vl;
    }
    void display()
    {cout<<"this is an amaizing video with title"<<title<<endl;
    cout<<"ratings:"<<rating<<"out of 5 stars"<<endl;
    cout<<"length of this videos is:"<<vidlength<<" minutes"<<endl;}
};
class text:public cwh{
    int words;
    public:
    text(string s, float r, int wc):cwh(s,r)
    {
        words=wc;
    }
    void display()
    {
        cout<<"this is an amaizing video with title:"<<title<<endl;
    cout<<"ratings:"<<rating<<"out of 5 stars"<<endl;
    cout<<"number of words in this text tutorial is:"<<words<<" minutes"<<endl;
    }
};

int main()
{
    string title;
    float rating,vl;
    int words;
    // // for videos
    // title="this is c++ tutorial";
    // vl=4.65;
    // rating =4.89;
    // video cvideo(title,rating,vl);
    // cvideo.display();
    
    // for text
    title="this is c++ tutorial";
    words=465;
    rating =4.1;
    text t(title,rating,words);
    t.display();
    return 0;
}