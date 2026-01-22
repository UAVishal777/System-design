#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ModelTrainer{
    public:

    void trainPipeline(const string&dataPath, const string&modelPath){
        loadData(dataPath);
        preprocessData();
        trainModel();
        evaluateModel();
        saveModel(modelPath);
    }

    protected:

    void loadData(const string&path){
        cout<<"Loading data from "<<path<<endl;
    }

    virtual void preprocessData(){
        cout<<"Preprocessing data using default method"<<endl;
    }

    virtual void trainModel()=0;
    virtual void evaluateModel()=0;

    virtual void saveModel(const string&path){
        cout<<"Saving model to "<<path<<endl;
    }


};

//Concrete Subclass for Neural Network
class NeuralNetworkTrainer: public ModelTrainer{
    protected:
    void preprocessData() override{
        cout<<"Preprocessing data using normalization"<<endl;
    }

    void trainModel() override{
        cout<<"Training Neural Network model"<<endl;
    }

    void evaluateModel() override{
        cout<<"Evaluating Neural Network model"<<endl;
    }

    void saveModel(const string&path) override{
        cout<<"Saving Neural Network model to "<<path<<endl;
    }
};

class DecisionTreeTrainer: public ModelTrainer{
    protected:
    void trainModel() override{
        cout<<"Training Decision Tree model"<<endl;
    }

    void evaluateModel() override{
        cout<<"Evaluating Decision Tree model"<<endl;
    }
};

int main(){

    cout<<"Neural Network Training Process:"<<endl;
    ModelTrainer* nnTrainer = new NeuralNetworkTrainer();
    nnTrainer->trainPipeline("data/train.csv", "models/nn_model.dat");
    delete nnTrainer;

    cout<<"\nDecision Tree Training Process:"<<endl;
    ModelTrainer* dtTrainer = new DecisionTreeTrainer();
    dtTrainer->trainPipeline("data/train.csv", "models/dt_model.dat");
    delete dtTrainer;


    return 0;
}