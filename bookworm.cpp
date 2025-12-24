#include <iostream>
#include <string>
#include <clocale>
#include <time.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

#define MAX_COUNT 10

// Yapiyi her kitap bir nesne olacak sekilde gï¿½ncelledik
struct Book {
    int serial_number;
    string title;
    string author;
    
};

// Global degisken: Veriler tï¿½m fonksiyonlar tarafindan erisilebilir olur
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
void save_books_to_file() {
    ofstream outFile("books.dat");
    if (outFile.is_open()) {
    	
        outFile << "Seri No | Baslik | Yazar" << endl;
        for (int i = 0; i < current_book_count; i++) {
            outFile << library[i].serial_number << " | " << library[i].title << " | " << library[i].author << endl;
        }
        outFile.close();
    }
}


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
	system("cls");
    if (current_book_count >= MAX_COUNT) {
        cout << "Kï¿½tï¿½phane dolu!\n";
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
        // Kï¿½ï¿½ï¿½k bir ipucu: if blogunun iï¿½indeki ELSE BREAK kismini sildiginden emin ol!
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
    save_books_to_file();
}


void getbook(string title) {
	system("cls");
	bool found = false;
	if(title == ""){
	
	    string name_to_find;
	    // Tamponda kalan her seyi temizle (ï¿½zellikle seï¿½imden kalan Enter karakteri)
	    cin.ignore(1000, '\n'); 
	
	    cout << "\nKitap Ismi Giriniz: ";
	    getline(cin, name_to_find); // Artik kullanici girisini dï¿½zgï¿½n bekler
	    	
	    	
		title = name_to_find;
	}
    for (int k = 0; k < current_book_count; k++) {
        // Kï¿½ï¿½ï¿½k bir ipucu: if blogunun iï¿½indeki ELSE BREAK kismini sildiginden emin ol!
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
	system("cls");
    cout << "\nKütüphane Listesi:\n";

    for (int i = 0; i < current_book_count; i++) {
        cout << " -> " << library[i].title << " (" << library[i].author << ")" << " Seri no: " << library[i].serial_number << endl;
    }
}


void deleteBook(string title){
	system("cls");
	bool deleted = false;
	if(title == ""){
	    cin.ignore(1000, '\n'); 
	
	    cout << "\nKitap Ismi Giriniz: ";
	    getline(cin, title); // Artik kullanici girisini dï¿½zgï¿½n bekler
	}
    for (int d = 0; d < current_book_count; d++) {
        // Kï¿½ï¿½ï¿½k bir ipucu: if blogunun iï¿½indeki ELSE BREAK kismini sildiginden emin ol!
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
    
    		if(deleted){
			
            cout << "\n--- KITAP SILINDI ---" << endl;
            current_book_count--;
            save_books_to_file();
			}else{
				cout << "\n BELIRTILEN KITAP BULUNAMADI!!\n";
			}
    
	
}

int main() {
	cout << "Program Loaded to RAM...";
	system("pause");
	setlocale(LC_ALL, "Turkish");
	readybooks();
	display_books();
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
    save_books_to_file();
    return 0;
}
