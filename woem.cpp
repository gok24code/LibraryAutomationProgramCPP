#include <iostream>
#include <string>
#include <clocale>
#include <time.h>
#include <stdlib.h>
using namespace std;

#define MAX_COUNT 10

// Yapiyi her kitap bir nesne olacak sekilde güncelledik
struct Book {
    int serial_number;
    string title;
    string author;
    
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
    
    bool foundExist = false;
    int serial;
	string title,author;

    cout << "\nKitap Ekleme:\n";
    cout << "Seri No: ";
    cin >> serial;

    cin.ignore();
    cout << "Baslik: ";
    getline(cin, title);

    cout << "Yazar: ";
    getline(cin, author);
     
	for (int a = 0; a < current_book_count; a++) {
        // Küçük bir ipucu: if blogunun içindeki ELSE BREAK kismini sildiginden emin ol!
        if ("-NULL-" == library[a].title) {
    
            library[a].title = title;
			library[a].author = author;
			library[a].serial_number = serial;
			
			foundExist = true;
            break; 
        }
    }
    if (!foundExist)
	{
	
            library[current_book_count].title = title;
			library[current_book_count].author = author;
			library[current_book_count].serial_number = serial;
			}
    current_book_count++; // Kitap sayisini artir
    cout << "Kitap basariyla eklendi!\n";
}


void getbook(string title) {
	bool found = false;
	if(title == ""){
	
	    string name_to_find;
	    // Tamponda kalan her seyi temizle (özellikle seçimden kalan Enter karakteri)
	    cin.ignore(1000, '\n'); 
	
	    cout << "\nKitap Ismi Giriniz: ";
	    getline(cin, name_to_find); // Artik kullanici girisini düzgün bekler
	    	
	    	
		title = name_to_find;
	}
    for (int k = 0; k < current_book_count; k++) {
        // Küçük bir ipucu: if blogunun içindeki ELSE BREAK kismini sildiginden emin ol!
        if (title == library[k].title) {
            cout << "\n--- KITAP BULUNDU ---" << endl;
            cout << "Baslik: " << library[k].title << endl;
            cout << "Yazar: " << library[k].author << endl;
            cout << "Seri No: " << library[k].serial_number << endl;
            found = true;
            break; 
        }
    }

    if (!found) cout << "\n'" << title << "' isimli kitap bulunamadi.\n";
}

void display_books() {

    cout << "\nKütüphane Listesi:\n";

    for (int i = 0; i < current_book_count; i++) {
        cout << " -> " << library[i].title << " (" << library[i].author << ")" << " Seri no: " << library[i].serial_number << endl;
    }
}


void deleteBook(string title){
	
	bool deleted = false;
	if(title == ""){
	    cin.ignore(1000, '\n'); 
	
	    cout << "\nKitap Ismi Giriniz: ";
	    getline(cin, title); // Artik kullanici girisini düzgün bekler
	}
    for (int d = 0; d < current_book_count; d++) {
        // Küçük bir ipucu: if blogunun içindeki ELSE BREAK kismini sildiginden emin ol!
        if (title == library[d].title) {
            cout << "\n--- KITAP SILINIYOR ---" << endl;
            cout << "Baslik: " << library[d].title << endl;
            cout << "Yazar: " << library[d].author << endl;
            cout << "Seri No: " << library[d].serial_number << endl;
            library[d].title = "-NULL-";
			library[d].author = "-NULL-";
			library[d].serial_number = 0;
			deleted = true;
            break; 
        }
    }
    
            cout << "\n--- KITAP SILINDI ---" << endl;
            current_book_count--;
    
    
	
}

int main() {
	setlocale(LC_ALL, "Turkish");
	readybooks();
	
    int choice;

	while(choice != 5){
        cout << "\n1. Ekle | 2. Ara | 3. Listele | 4. Sil | 5.Çikis\nSeçiminiz: ";
        cin >> choice;

        switch (choice) {

        case 1: 
			add_book(); break;

        case 2: 
			getbook(""); break;

        case 3: 
			display_books(); break;

		case 4:
			deleteBook("");
		}
        
	}
    return 0;
}
