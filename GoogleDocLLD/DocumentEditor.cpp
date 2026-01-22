/**
 * Text
 * Image
 */

//have text and images we can render it here
#include<bits/stdc++.h>
using namespace std;

//Abstraction for DE
class DocumentElement{

    // vector<string>docs; //can be of type text or image

    public:
    // void addText(string txt){
    //     docs.push_back(txt);
    //     cout<<"Added text in doc"<<txt<<endl;
    // }

    // void addImage(string img){
    //     docs.push_back(img);
    //     cout<<"Added image in doc"<<img<<endl;
    // }

    virtual string render()=0;
    // void saveToFile(){
    //     cout<<"Saved to file"<<endl;
    // }
};

class TextElement: public DocumentElement{

    private:
        string text;

    public:
        TextElement(string text){
            this->text=text;
        }
        string render()override{
            return text;
        }
};

class ImageElement: public DocumentElement{
    private:
        string imgPath;
    
    public:
        ImageElement(string path){
            this->imgPath=path;
        }
        string render() override{
            return "[Imagepath "+ imgPath + "]";
        }
};

class NewLineElement: public DocumentElement{
    public:
    string render()override{
        return "\n";
    }
};



//this class has 1 to many relationship of Document Elements
class Document{

    private:
    vector<DocumentElement*>docElements;


    public:

    void addElement(DocumentElement* doc){
        docElements.push_back(doc);
        cout<<"Added document in docs"<<endl;
    }


    string render(){
        string result;
        for(auto *doc: docElements){
            result = result + doc->render();
        }
        return result;
    }

};

// Storage system abstraction

class Persistence{

    public:
    virtual void save(string data)=0;

};

class FileStorage: public Persistence{
    public:
        void save(string data) override{
            cout<<"saved to file"<<endl;
        }

};

class DBStorage:public Persistence{
    public:
        void save(string data)override{
            cout<<"Saved to DB"<<endl;
        }
};

//this class will manage client interaction
class DocumentEditor{
    private:
    Document* document;
    Persistence* storage;
    string renderDoc;

    public:
    DocumentEditor(Document* doc, Persistence* storage){
        this->document= doc;
        this->storage = storage;
    }

    void addText(string txt){
        document->addElement(new TextElement(txt));
    }

    void addImage(string imgPath){
        document->addElement(new ImageElement(imgPath));
    }

    void addNewLine(){
        document->addElement(new NewLineElement());
    }

    string renderDocument(){
        if(renderDoc.empty()){
            renderDoc = document->render();
        }
        return renderDoc;
    }

    void saveDocument(){
        storage->save(renderDoc);
    }
};
int main(){

    Document* document = new Document();
    Persistence* persistence = new FileStorage();

    DocumentEditor* editor= new DocumentEditor(document, persistence);

    editor->addText("Added text in doc");
    editor->addNewLine();
    editor->addImage("https://imagepath.com");
    editor->addNewLine();

    cout<<editor->renderDocument()<<endl;
    editor->saveDocument();


    return 0;
}




