#include <iostream>
using namespace std;

template<typename T>
class Node {
private:
    T data; //veri
    Node *next, *prev; //sonraki, önceki

public:

    Node(const T &data, Node<T> *next = NULL, Node<T> *prev = NULL) {
        this->data = data;
        this->next = next; //sonraki
        this->prev = prev; //önceki
    }

    //DList class will be provided access to private variables
    template<class Nesne> friend class DList;
};

template<class Nesne>
class DList {
private:
    Node<Nesne> *head, *tail;
    int elemanSayisi; //eleman sayısı

    Node<Nesne>* oncekiDugum(int inx) {
        Node<Nesne> *temp = head;
        int cnt = 0;
        while (temp != NULL) {
            if (cnt == inx - 1)
                break; //konum bulundu
            temp = temp->next;
            cnt++;
        }
        return temp;
    }
public:

    DList() {
        head = NULL; //ilk
        tail = NULL; //son
        elemanSayisi = 0;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void push_front(const Nesne& data) {
        Node<Nesne> *yeni = new Node<Nesne>(data);
        //Liste boş mu
        if (head == NULL) {
            head = yeni;
            tail = yeni;
        } else {
            head->prev = yeni;
            yeni->next = head;
            head = yeni;
        }
        elemanSayisi++;
    }

    void push_back(const Nesne& data) {
        Node<Nesne>* yeni = new Node<Nesne>(data);
        //Liste boşmu
        if (head == NULL) {
            head = yeni;
            tail = yeni;
        } else {
            tail->next = yeni;
            yeni->prev = tail;
            tail = yeni;
        }
        elemanSayisi++;
    }

    void insert(int konum, const Nesne& data) {
        if (konum < 0 | konum > elemanSayisi) {
            cout << "Gecersiz konum";
            return;
        }
        if (konum == 0)
            push_front(data);
        else if (konum == elemanSayisi)
            push_back(data);
        else {
            Node<Nesne> *yeni = new Node<Nesne>(data);
            Node<Nesne> *temp = oncekiDugum(konum);
            // baglantıyı yap
            yeni->next = temp->next;
            temp->next->prev = yeni;
            temp->next = yeni;
            yeni->prev = temp;
            elemanSayisi++;
        }

    }

    void remove(int konum) {
        if (head == NULL) cout << "Bos Liste";
        if (konum < 0 | konum >= elemanSayisi) cout << "Gecersiz Konum";
        Node<Nesne> *temp;
        if (konum == 0) {
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            delete temp;
        } else {
            //konum-1deki dugum
            temp = oncekiDugum(konum);
            //silinecek dugum
            Node<Nesne> *eskiDugum=temp->next;
            temp->next=eskiDugum->next;
            //silinecek eleman en sonda değilse
            if(temp->next!=NULL)
                eskiDugum->next->prev=temp;
            
            delete eskiDugum;
        }
        
        
        elemanSayisi--;
    }

    Nesne& at(int konum) {
    if (konum < 0 || konum >= elemanSayisi)
        throw out_of_range("Gecersiz konum");

    Node<Nesne>* temp = head;
    int sayac = 0;
    while (temp != nullptr) {
        if (sayac == konum) {
            return temp->data;
        }
        temp = temp->next;
        sayac++;
    }

    return tail->data;
	}


    void clear() {
        Node<Nesne> *temp = head;
        Node<Nesne> *delnode;
        while (temp != NULL) {
            delnode = temp;
            temp = temp->next;
            delete delnode;
        }
        head = NULL;
        tail = NULL;
        elemanSayisi = 0; //
    }

    friend ostream& operator<<(ostream &out, DList<Nesne> &list) {
        cout << ">------Liste elemanlari---------<" << endl;
        cout << "list.length()=" << list.length() << endl;
        for (int i = 0; i < list.length(); i++) {
            out << list.at(i) << " ";
        }
        out << endl;
        return out;
    }

    int length() {
        return elemanSayisi;
    }

};

int main() {

    DList<string> list;
    list.push_front("elma");
    list.push_front("portakal");
    list.insert(0, "patates");
    list.push_back("lahana");
    list.push_back("salata");
    list.insert(1, "mandalina");
    list.insert(6, "armut");

    cout << "Listeyi Yazdir" << endl;
    cout << list;

    list.remove(5);

    cout << "Listeyi Yazdir" << endl;
    cout << list;
    return 0;
}