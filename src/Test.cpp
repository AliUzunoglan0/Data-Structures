/**        
 * @file  Test.cpp  
 * @description Bu program bir text dosyasında belli düzene göre yazılmış satırları okuyarak işlemler yapmaktadır.
 * @course  1-A   
 * @assignment  1  
 * @date  06/11/2021   
 * @author  Ali Tayyip Uzunoglan(ali.uzunoglan@ogr.sakarya.edu.tr)
 **/
#include <iostream>
#include <fstream>
#include <sstream>
#include "DoublyLinkedList.h"
#include "Node.h"
using namespace std;

int main()
{
    DoublyLinkedList *list = new DoublyLinkedList(); // Heap bellek bölgesinde çift yönlü bağıl liste oluşturuluyor.
    ifstream readFile("Veri.txt");
	string satir = "";
	int index=0;
	string addName="";
	
	
	
	while ( getline(readFile, satir) ){
		if(satir.substr(0,1) == "E")
		{
			stringstream ss(satir.substr(2));
			ss >> index;
			addName = satir.substr(4,(satir.size()-5));
			list->copyIleri(index,addName);
		}else if(satir.substr(0,1) == "S")
		{
			stringstream ss(satir.substr(2));
			ss >> index;
			list->copyReverse(index);
		}
    }
	
    list->printList();         // Listenin içeriği printList fonksiyonu ile ekrana yazdırılıyor.
    delete list;               //Heap bellek bölgesinde çöp birikmemesi için oluşturulan nesne siliniyor.
}