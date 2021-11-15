/**        
 * @file  DoublyLinkedList.cpp
 * @description  Bu program bir text dosyasında belli düzene göre yazılmış satırları okuyarak işlemler yapmaktadır.
 * @course  1-A   
 * @assignment  1
 * @date  06/11/2021   
 * @author  Ali Tayyip Uzunoglan(ali.uzunoglan@ogr.sakarya.edu.tr)
 **/

#ifndef List
#include "Node.h"
#include "DoublyLinkedList.h"
#endif

void DoublyLinkedList::addEnd(string kelime) // Çift yönlü bağlı listenin sonuna eleman eklemek için bu parametreli fonksiyon kullanılıyor.
{
    if (root == NULL) // Düğüme eklenecek ilk eleman için özel işlem yapılıyor.
    {
        root = new Node();
        root->kelime = kelime;
        root->next = NULL;
        return;
    }

    Node *iter = root;
    while (iter->next != NULL) //iter değişkeni listenin son elemanına ulaşana kadar while döngüsü ile ilerliyor.
    {
        iter = iter->next;
    }
    iter->next = new Node();
    iter->next->prev = iter; // Yeni oluşturulan düğümün previ itere bağlanıyor
    iter->next->kelime = kelime;
    iter->next->next = NULL; // Listenin son elemanının nextinin NULL u göstermesi sağlanıyor.
}

void DoublyLinkedList::copyReverse(int index)  //geriye doğru kopyalama işlemi yapılmaktadır.
{
	int nodeCount = 0;
	Node *iter = root;
    while (iter->next != NULL) //listenin düğüm sayısını bulmak için sonuna kadar ilerleniyor.
    {
        iter = iter->next;
		nodeCount++;
    }
	if(index>nodeCount)  //Eğer girilen değer düğüm sayısından büyükse son düğüm siliniyor.
	{
		iter = iter->prev;
		iter->next = NULL;
		return;
	}
	Node *newIter = root;
	for(int i = 0; i<index-1;i++)  // iteratorun belirtilen düğüme gitmesi sağlanıyor.
	{
		newIter = newIter->next;
	}
	while(newIter->next != NULL)   //ve sonrasında listenin sonuna kadar gerekli kopyalama işlemi gerçekleştiriliyor.
	{
		newIter->kelime=newIter->next->kelime;
		newIter = newIter->next;
	}
	iter = iter->prev;
	iter->next = NULL;
}

void DoublyLinkedList::copyIleri(int index, string nameForAdd)  //ileri doğru kopyalama işlemi yapılmaktadır.
{
	if (root == NULL) // eğer liste null ise ilk düğüm için işlem yapılıyor.
    {
        root = new Node();
        root->kelime = nameForAdd;
        root->next = NULL;
        return;
    }
	int nodeCount = 0;
	Node *iter = root;
    while (iter->next != NULL) //iter değişkeni listenin son elemanına ulaşana kadar while döngüsü ile ilerliyor.
    {
        iter = iter->next;
		nodeCount++;
    }
	if(index>nodeCount)   // eğer belirtilen index düğüm sayısından büyük ise listenin sonuna eklenmesini sağlıyor.
	{
		addEnd(nameForAdd);
		return;
	}
	iter->next = new Node();
	iter->next->prev = iter; 
    iter->next->kelime = iter->kelime;
	while(nodeCount-(index-1) != 0)   //iteratorun belirtilen indexe gitmesi sağlanıyor
	{
		iter->kelime = iter->prev->kelime;
		iter = iter->prev;
		nodeCount--;
	}
	iter->kelime = nameForAdd;
}

void DoublyLinkedList::printList() // Listenin içeriği ekrana yazdırılıyor.
{
    Node *temp = root;
    while (temp != NULL)
    {
		if (temp->next != NULL) {
			cout << temp->kelime << "  <-->  ";
			temp = temp->next;
		}
		else {
			cout << temp->kelime << endl;
			temp = temp->next;
		}
    }
}

DoublyLinkedList::~DoublyLinkedList() // İşlemler sonunda root nesnesi silinerek heap bellek bölgesinde çöp oluşumu engelleniyor.
{
    delete root;
}
