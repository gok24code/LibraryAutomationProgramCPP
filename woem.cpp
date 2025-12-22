#include <iostream>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

#define MAX_COUNT 10

// Yapiyi her kitap bir nesne olacak sekilde güncelledik
struct Book {
    int serial_number;
    string title;
    string author;
    int year;
};

// Global degisken: Veriler tüm fonksiyonlar tarafindan erisilebilir olur
Book library[MAX_COUNT];

int current_book_count = 0;

string names[10] = {
    "The Great Gatsby", "Moby Dick", "War and Peace", "The Alchemist", "1984", 
    "The Metamorphosis", "Ulysses", "Brave New World", "The Catcher in the Rye", "To Kill a Mockingbird"
};

string authors[10] = {
    "F. Scott Fitzgerald", "Herman Melville", "Leo Tolstoy", "Paulo Coelho", "George Orwell", 
    "Franz Kafka", "James Joyce", "Aldous Huxley", "J.D. Salinger", "Harper Lee"
};

void readybooks(){
	srand(time(0));
	bool bookTaken [MAX_COUNT] = {false};
	int i = -1;
	while(current_book_count != MAX_COUNT){
		
	do{
		i++;
	}while(bookTaken[i] == true);
		bookTaken[i] = true;
		library[i].title = names[i];
		library[i].author = authors[i];
		library[i].serial_number = (rand() % 100) + 100;
		current_book_count++;
	}
}


void add_book() {
    if (current_book_count >= MAX_COUNT) {
        cout << "Kütüphane dolu!\n";
        return;
    }

    cout << "\nKitap Ekleme:\n";
    cout << "Seri No: ";
    cin >> library[current_book_count].serial_number;

    cin.ignore();
    cout << "Baslik: ";
    getline(cin, library[current_book_count].title);

    cout << "Yazar: ";
    getline(cin, library[current_book_count].author);

    cout << "Basim Yili: ";
    cin >> library[current_book_count].year;

    current_book_count++; // Kitap sayisini artir
    cout << "Kitap basariyla eklendi!\n";
}


void getbook() {
    string name_to_find;
    bool found = false;

    // Tamponda kalan her seyi temizle (özellikle seçimden kalan Enter karakteri)
    cin.ignore(1000, '\n'); 

    cout << "\nKitap Ismi Giriniz: ";
    getline(cin, name_to_find); // Artik kullanici girisini düzgün bekler

    for (int k = 0; k < current_book_count; k++) {
        // Küçük bir ipucu: if blogunun içindeki ELSE BREAK kismini sildiginden emin ol!
        if (name_to_find == library[k].title) {
            cout << "\n--- KITAP BULUNDU ---" << endl;
            cout << "Baslik: " << library[k].title << endl;
            cout << "Yazar: " << library[k].author << endl;
            cout << "Seri No: " << library[k].serial_number << endl;
            found = true;
            break; 
        }
    }

    if (!found) cout << "\n'" << name_to_find << "' isimli kitap bulunamadi.\n";
}

void display_books() {

    cout << "\nKütüphane Listesi:\n";

    for (int i = 0; i < current_book_count; i++) {
        cout << " -> " << library[i].title << " (" << library[i].author << ")" << " Seri no: " << library[i].serial_number << endl;
    }
}

int main() {
	setlocale(LC_ALL, "Turkish");
	readybooks();
	
    int choice;

	while(choice != 4){
        cout << "\n1. Ekle | 2. Ara | 3. Listele | 4. Çikis\nSeçiminiz: ";
        cin >> choice;

        switch (choice) {

        case 1: 
			add_book(); break;

        case 2: 
			getbook(); break;

        case 3: 
			display_books(); break;

		default:
			break;
        }
        
	}
    return 0;
}
