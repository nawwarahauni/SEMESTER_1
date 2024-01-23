#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<string>
#include<sstream>
using namespace std;


struct fooddata{

    string cerealtype2;
    string cerealtype1;
    double carbohydrate;
    double protein;
    double fat;

};

void inputFile(fooddata foodData, string cerealType1[], string cerealType2[], double carbohydrateW[], double proteinW[], double fatW[]){
    
    ifstream input("cerealData.txt");
    if(!input.is_open())
    cout << "im confused uhh" << endl;

    for(int i = 0; i < 10; i++){
        
        input >> foodData.cerealtype1 >> foodData.cerealtype2 >> foodData.carbohydrate >> foodData.protein >> foodData.fat;
        cerealType1[i] = foodData.cerealtype1;
        cerealType2[i] = foodData.cerealtype2;
        carbohydrateW[i] = foodData.carbohydrate;
        proteinW[i] = foodData.protein;
        fatW[i] = foodData.fat;

    }
    input.close();
}

void calconvert(double carbohydrateW[], double proteinW[], double fatW[], double carbohydrateG[], double proteinG[], double fatG[]){
    for (int i = 0; i < 10; i++){

        carbohydrateG[i] = carbohydrateW[i] * 28.35;
        proteinG[i] = proteinW[i] * 28.35;
        fatG[i] = fatW[i] * 28.35;

    }
}

void calDV(double carbohydrateG[], double proteinG[], double fatG[], double carboDV[], double proteinDV[], double fatDV[]){

    for(int i = 0; i < 10; i++){

        carboDV[i] = (carbohydrateG[i]/300.00) * 100.00;
        proteinDV[i] = (proteinG[i]/50.00) * 100.00;
        fatDV[i] = (fatG[i]/65.00) * 100.00;
    }

}

void category(double carboDV[], double proteinDV[], double fatDV[], string catcarbo[], string catprotein[], string catfat[], double avgcarbo, double avgprotein, double avgfat, string catavgcarb[], string catavgprot[], string catavgfat[]){

    for(int i = 0; i < 10; i++){

        if(carboDV[i] < 5)
        catcarbo[i] = "Low";
        else if(carboDV[i] >= 5 && carboDV[i] < 20)
        catcarbo[i] = "Moderate";
        else
        catcarbo[i] = "High";

        if(proteinDV[i] < 5)
        catprotein[i] = "Low";
        else if(proteinDV[i] >= 5 && proteinDV[i] < 20)
        catprotein[i] = "Moderate";
        else
        catprotein[i] = "High";

        if(fatDV[i] < 5)
        catfat[i] = "Low";
        else if(fatDV[i] >= 5 && fatDV[i] < 20)
        catfat[i] = "Moderate";
        else
        catfat[i] = "High";

        


    }

    if(avgcarbo < 5)
        catavgcarb[0] = "Low";
        else if(avgcarbo >= 5 && avgcarbo < 20)
        catavgcarb[0] = "Moderate";
        else
        catavgcarb[0]= "High";

        if(avgprotein < 5)
        catavgprot[0] = "Low";
        else if(avgprotein >= 5 && avgprotein < 20)
        catavgprot[0] = "Moderate";
        else
        catavgprot[0] = "High";

        if(avgfat < 5)
        catavgfat[0] = "Low";
        else if(avgfat >= 5 && avgfat < 20)
        catavgfat[0] = "Moderate";
        else
        catavgfat[0] = "High";

    

}
void averageDV(double carboDV[], double proteinDV[], double fatDV[], double &avgcarbo, double &avgprotein, double &avgfat){

    for(int i = 0; i < 10; i++){
        avgcarbo += carboDV[i];
        avgprotein += proteinDV[i];
        avgfat += fatDV[i];
    }

    avgcarbo /= 10;
    avgprotein /= 10;
    avgfat /= 10;

}

void outputFile(string catcarbo[], string catprotein[], string catfat[], string cerealType1[], string cerealType2[], double carboDV[], double proteinDV[], double fatDV[],  double avgcarbo, double avgprotein, double avgfat, string catavgcarb[], string catavgprot[], string catavgfat[]){

    ofstream outFile("outputcereal.txt");

    outFile << "Type" << "             " << "    Carbohydrate" << "            " << "       Protein" << "             " << "             Fat" << endl;
    outFile << "========" << "           " << "  =============" << "           " << "     =============" << "           " << "      =============" << endl;

    for(int i = 0; i < 10; i++){
        outFile << cerealType1[i] << " " << cerealType2[i] << "            " << fixed << setprecision(1) << right << setw(5) << carboDV[i] << "%" << left << setw(12) << "(" + catcarbo[i] + ")" << "            " <<  left << setw(5) << proteinDV[i] << "%" << left << setw(12) << "(" + catprotein[i] + ")" << "           " << right << setw(5) << fatDV[i] << "%" << left << setw(12) << "(" + catfat[i] + ")" << endl;
    }

    
    outFile << "\n\nThe four cereal types produce an average DV of:" << endl;
    outFile << "\nCarbohydrate : " << avgcarbo << "%(" + catavgcarb[0] + ")" << endl;
    outFile << "Protein      : " << avgprotein << "%(" + catavgprot[0] + ")" << endl;
    outFile << "Fat          : " << avgfat << "%(" + catavgfat[0] + ")" << endl;
    outFile.close();
}

int main(){

    int choice1, choice2, counter = 1;
    string catcarbo[10], catprotein[10], catfat[10], catavgcarb[1], catavgprot[1], catavgfat[1];
    string cerealType2[10];
    string cerealType1[10];
 
    double carbohydrateW[10], proteinW[10], fatW[10];
    double carbohydrateG[10], proteinG[10], fatG[10];
    double carboDV[10], proteinDV[10], fatDV[10];
    double avgcarbo, avgprotein, avgfat;
    double container[10];
    fooddata foodData;

    inputFile(foodData, cerealType1, cerealType2, carbohydrateW, proteinW, fatW);
    cout << "all good" << endl;

    calconvert(carbohydrateW, proteinW, fatW, carbohydrateG, proteinG, fatG);
    calDV(carbohydrateG, proteinG, fatG, carboDV, proteinDV, fatDV);
    averageDV(carboDV, proteinDV, fatDV, avgcarbo, avgprotein, avgfat);
    category(carboDV, proteinDV, fatDV, catcarbo, catprotein, catfat, avgcarbo, avgprotein, avgfat, catavgcarb, catavgprot, catavgfat);
   

    cout << "1. Carbohydrate \n2. Protein \n3. Fat" << endl;
    cout << "Please Enter your choice >> ";
    cin >> choice1;

    cout << "\n\n";
    cout << "1. Low \n2. Moderate \n3. High" << endl;
    cout << "Please Enter your choice >> ";
    cin >> choice2;

    string option1[3] = {"Carbohydrate", "Protein", "Fat"};
    string option2[3] = {"Low", "Moderate", "High"};

    cout << "\nlist of cereal(s) with " << option2[(choice2 - 1)] << " amount of " << option1[(choice1 - 1)] << endl;
    


if(choice1 == 1){
        if(choice2 == 1){
            for(int i = 0; i < 10; i++){
               if (catcarbo[i] == "Low"){
                    cout << counter << ". Cereal" << " " << cerealType2[i] << endl;
                    counter++;
               }
        
            }

        }
        else if(choice2 == 2){
            for(int i = 0; i < 10; i++){
               if (catcarbo[i] == "Moderate"){
                    cout << counter << ". Cereal" << " " << cerealType2[i] << endl;
                    counter++;
               }
        
            }
        }
        else{
            for(int i = 0; i < 10; i++){
               if (catcarbo[i] == "High"){
                    cout << counter << ". Cereal" << " " << cerealType2[i] << endl;
                    counter++;
               }
            }
        }
        
    }
else if(choice1 == 2){
        if(choice2 == 1){
            for(int i = 0; i < 10; i++){
               if (catprotein[i] == "Low"){
                    cout << counter << ". Cereal" << " " << cerealType2[i] << endl;
                    counter++;
               }
        
            }

        }
        else if(choice2 == 2){
            for(int i = 0; i < 10; i++){
               if (catprotein[i] == "Moderate"){
                    cout << counter << ". Cereal" << " " << cerealType2[i] << endl;
                    counter++;
               }
        
            }
        }
        else{
            for(int i = 0; i < 10; i++){
               if (catprotein[i] == "High"){
                    cout << counter << ". Cereal" << " " << cerealType2[i] << endl;
                    counter++;
               }
            }
        }
        
    }
else if(choice1 == 3){
        if(choice2 == 1){
            for(int i = 0; i < 10; i++){
               if (catfat[i] == "Low"){
                    cout << counter << ". Cereal" << " " << cerealType2[i] << endl;
                    counter++;
               }
        
            }

        }
        else if(choice2 == 2){
            for(int i = 0; i < 10; i++){
               if (catfat[i] == "Moderate"){
                    cout << counter << ". Cereal" << " " << cerealType2[i] << endl;
                    counter++;
               }
        
            }
        }
        else{
            for(int i = 0; i < 10; i++){
               if (catfat[i] == "High"){
                    cout << counter << ". Cereal" << " " << cerealType2[i] << endl;
                    counter++;
               }
            }
        }
        
    }

    outputFile(catcarbo, catprotein, catfat, cerealType1, cerealType2, carboDV, proteinDV, fatDV,  avgcarbo, avgprotein, avgfat, catavgcarb, catavgprot, catavgfat);


    


    return 0;

    

}