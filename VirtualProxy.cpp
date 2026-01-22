#include <iostream>
#include <string>
using namespace std;

class IImage{
    public:
    virtual void display()=0;
    virtual ~IImage()=default;
};

class RealImage: public IImage{
    private:
    string fileName;

    public:
    RealImage(string file){
        this->fileName=file;
        cout<<"Loading image from disk: "<<fileName<<endl;
    }

    void display() override{
        cout<<"Displaying image: "<<fileName<<endl;
    }
};

class ImageProxy: public IImage{
    private:
    RealImage* realImage;
    string fileName;

    public:
    ImageProxy(string file){
        this->fileName=file;
        realImage=nullptr;
    }

    void display()override{
        if(realImage == nullptr){
            realImage= new RealImage(fileName);
        }
        realImage->display();
    }
};

int main(){

    IImage* image1 = new ImageProxy("photo1.jpg");
    image1->display(); // Loads and displays the image
    ImageProxy* imageProxy = dynamic_cast<ImageProxy*>(image1);
    if(imageProxy){
        imageProxy->display(); // Displays the image without loading
    }

    return 0;
}