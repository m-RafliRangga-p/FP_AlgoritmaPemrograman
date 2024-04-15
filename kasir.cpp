#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <ctime>
using namespace std;

int main () {
	//Deklarasi Variabel
	string username,password,pass,print,ulangi;
	int jumlah_belanjaan,pilihan;
	float total_harga = 0,uang,kembalian;
	char id_barang[150][10];
	char nama_barang[150][150];
	int jumlah_barang[150];
	float harga[150];
	float total_barang[150];
	
	// Reminder User Password
		kasir :
        cout << "Selamat Datang di Aplikasi Kasir Amikom-Mart \n";
        cout << "Username anda adalah 'Amikom' dan Password anda adalah 'Mart' \n";
        system("Timeout 10");
        system("cls");

        // form login
        cout << "Silahkan Login ke Account Anda \n";
        cout << "Username: ";
        cin >> username;
		if (username == "Amikom"){
			pass :
			cout << "Password: ";
			cin >> password;
			if (password == "Mart") {
				system("cls");
				
				menu :
				cout << "=========================================== \n";
				cout << "1. Menghitung Total Belanjaan & Pembayaran \n";
				cout << "2. Exit/Keluar \n";
				cout << "=========================================== \n";
				cout << "Masukkan Menu Pilihan Anda = ";
				cin >> pilihan;
				system("cls");
					
					if (pilihan == 1){
					cout << "===== Selamat Datang Di Kasir Amikom-Mart ===== \n";
					cout << "Silahkan Masukkan Jumlah Barang Belanjaan : ";
					cin >> jumlah_belanjaan;
					system("cls");
					
					for (int a=0;a<jumlah_belanjaan;a++) {
					cout << a+1 << " Masukkan ID Barang : ";
					cin >> id_barang[a];
					cout << endl;
					cout << "  Masukkan Nama Barang : ";
					cin.ignore();
					cin.getline(nama_barang[a], 150);
					cout << endl;
					cout << "  Masukkan Jumlah Barang : ";
					cin >> jumlah_barang[a];
					cout << endl;
					cout << "  Masukkan Harga Barang : ";
					cin >> harga[a];
					cout << endl;
					cout << "-------------------------------------------------\n";	
					}
					system("cls");
					for (int b=0;b<jumlah_belanjaan;b++){
						total_barang[b] = jumlah_barang[b] * harga[b];
						total_harga += total_barang[b];
					}
					cout << fixed;
					cout << "Total \t: " <<setprecision(3) << total_harga << endl;
					cout << "Nominal Pembayaran : ";
					cin >> uang;
					system("cls");
					cout << "\t\t Amikom-Mart \t\t\n";
					cout << "\t Jl. Ring Road Utara, Ngringin,\n";
					cout << "\t Condongcatur, Depok, Sleman, DIY\n";
					cout << "\t Tanggal \t: ";system("date/t");
					cout << "\t Waktu \t\t: ";system("time/t");
					cout << "_______________________________________________\n";
					for (int c=0;c<jumlah_belanjaan;c++){
						cout << fixed;
						cout << id_barang[c] << "\t"<< nama_barang[c] << "\t\n"; 
						cout << jumlah_barang[c] << "\t" << setprecision(3) << total_barang[c] << endl;
					}
					cout << "_______________________________________________\n";
					cout << fixed;
					cout << "Total \t\t: " <<setprecision(3) << total_harga << endl;
					cout << "Pembayaran \t: " <<setprecision(3) << uang << endl;
					kembalian = uang - total_harga;
					cout << "Kembalian \t: " << kembalian << endl;
					cout << "_______________________________________________\n";
					cout << "\t Terimakasih Telah \n";
					cout << "\t Berbelanja Di\n";
					cout << "\t Toko Kami\n";

                    cout << "Apakah anda ingin mencetaknya? (y/n) \n";
                    cin >> print;

                    if (print == "y") {
                        ofstream nota;
                        nota.open ("nota.txt");
                        nota << "\t\t Amikom-Mart \t\t\n";
                        nota << "\t Jl. Ring Road Utara, Ngringin,\n";
                        nota << "\t Condongcatur, Depok, Sleman, DIY\n";
                        time_t now = time(0);
                        char* date_time = ctime(&now);
                        nota << "\t " << date_time << endl;
                        nota << "_______________________________________________\n";
                        for (int c=0;c<jumlah_belanjaan;c++){
                            nota << fixed;
                            nota << id_barang[c] << "\t"<< nama_barang[c] << "\t\n"; 
                            nota << jumlah_barang[c] << "\t" << setprecision(3) << total_barang[c] << endl;
                        }
                        nota << "_______________________________________________\n";
                        nota << fixed;
                        nota << "Total \t: " <<setprecision(3) << total_harga << endl;
                        nota << "Pembayaran \t: " <<setprecision(3) << uang << endl;
                        nota << "Kembalian \t: " << kembalian << endl;
                        nota << "_______________________________________________\n";
                        nota << "\t Terimakasih Telah \n";
                        nota << "\t Berbelanja Di\n";
                        nota << "\t Toko Kami\n";
                        nota.close();
						
						total_harga = 0;
                        system("cls");
                        goto menu;
                    }
                    else {
						total_harga = 0;
                        goto menu;
                    }
				}
				else if (pilihan == 2) {
					goto exit;
				}
				else {
					cin.ignore();
					cout << "Pilihan salah, tekan enter untuk melanjutkan";
					cin.get();
					system("cls");
					goto menu;
				}
			}
			else {
				system("cls");
				cout << "Password Yang Anda Masukkan Salah!!\n";
				cout << "Apakah Anda Ingin Mencoba lagi? (y/n): ";
				cin >> pass;
				if (pass=="y"){
					goto pass;
				}
				else {
					cin.ignore();
				}
			}
		}
		else {
			system("cls");
			cout << "Username Anda Salah!!\n";
			cout << "Apakah Anda Ingin Mencobanya Lagi? (y/n)\n";
            cin >> ulangi;
            system("cls");
			if (ulangi == "y") {
				goto kasir;
			}
			else {
				goto exit;
			}
		}
	exit :
	
	return 0;
}