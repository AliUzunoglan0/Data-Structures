/**        
 * @file  DoublyLinkedList.h  
 * @description Bu program bir text dosyasında belli düzene göre yazılmış satırları okuyarak işlemler yapmaktadır.
 * @course  1-A   
 * @assignment 1 
 * @date  06/11/2021 
 * @author  Ali Tayyip Uzunoglan(ali.uzunoglan@ogr.sakarya.edu.tr)
 **/
#ifndef List_H
#define List_H
#include <iostream>
#include "Node.h"
using namespace std;

class DoublyLinkedList // Çift yönlü bağlı liste'nin ilgili sınıfı oluşturuluyor ve header dosyası olduğu için gövdeler yazılmıyor.
{
public:
    void addEnd(string);
    void printList();
	void copyIleri(int, string);
	void copyReverse(int);
    ~DoublyLinkedList();

private:
    Node *root;
};
#endif