# Drugstore_Data
## Tugas Besar Struktur Data tentang Hubungan Antara Apotik dan Obat yang Tersedia
-------------------------------------------------------------------------------
# Disusun Oleh : 
-------------------------------------------------------------------------------
### Bagja 9102 Kurniawan   ||| SID = 1301194020 
-------------------------------------------------------------------------------
### Manuel Benedict           ||| SID = 1301194182
-------------------------------------------------------------------------------
# IIIA/A3
>- Apotik/Drugstore as parent ( Single Linked List )
>- Obat/Medicine as child ( Circular Double Linked List )
>- Relasi ( Single Linked List )
-------------------------------------------------------------------------------
# Spesifikasi
-------------------------------------------------------------------------------
### Menu include
-------------------------------------------------------------------------------
>**1. Tambah apotik**_(Menerima input user, alokasi, dan insert last Parent)_<br>
>- akan search by id, jika id sama user diminta input ulang<br>
-------------------------------------------------------------------------------
>**2. Tambah obat**_(Menerima input user, alokasi, dan insert last Child)_<br>
>- akan search by id, jika id sama user diminta input ulang<br>
-------------------------------------------------------------------------------
>**3. Menambah obat pada apotik tertentu**_(Menerima input user, search, connect, insert last Relasi)_<br>
>- akan mengecek jika unputan redundan(sudah pernah dibuat sebelumnya) program akan meminta user memasukkan input baru<br>
-------------------------------------------------------------------------------
>**4. Menghapus obat pada apotik tertentu**_(Menerima input user, search, disconnect 1 relasi, delete after before input, dealokasi Relasi)_<br>
>- hanya menghapus 1 relasi
-------------------------------------------------------------------------------
>**5. Apotik tutup**_(Menerima input user, search, disconnect apotik, delete after before input, dealokasi Parent)_<br>
>- delete apotik(parent)<br>
>- menghapus relasi obat ke apotik x
-------------------------------------------------------------------------------
>**6. Obat yang penjualannya dilarang**_(Menerima input user, search, disconnect obat, delete after before input, dealokasi Child)_<br>
>- delete obat(child)<br>
>- menghapus relasi apotik ke obat x
-------------------------------------------------------------------------------
>**7. Mencari nomor izin apotik berdasarkan nama**_(Menerima input user, search, menampilkan info apotik)_<br>
>- search by name parent dan tampilkan no izin apotik yang dicari
-------------------------------------------------------------------------------
>**8. Mencari nomor izin apotik berdasarkan ID**_(Menerima input user, search, menampilkan info apotik)_<br>
>- search by id parent dan tampilkan no izin apotik yang dicari
-------------------------------------------------------------------------------
>**9. Mencari obat**_(Menerima input user, search, menampilkan info obat)_<br>
>- search by name child dan tampilkan infi child yang dicari
-------------------------------------------------------------------------------
>**10. Menampilkan apotik**_(Menampilkan info.namaApotik tiap elemen dalam list Parent)_<br>
-------------------------------------------------------------------------------
>**11. Menampilkan obat**_(Menampilkan info.namaObat tiap elemen dalam list Child)_<br>
-------------------------------------------------------------------------------
>**12. Menampilkan apotik yang memiliki obat tertentu**_(Menerima input user, search obat, menampilkan apotik yang memiliki obat x)_<br>
-------------------------------------------------------------------------------
>**13. Menampilkan obat yang dimiliki apotik tertentu**_(Menerima input user, search apotik, menampilkan obat yang dimiliki apotik x)_<br>
-------------------------------------------------------------------------------
>**14. Menghitung jumlah obat yang dimiliki apotik**_(Menerima input user, search apotik, menampilkan banyak obat yang dimiliki apotik x)_<br>
-------------------------------------------------------------------------------
>**15. Menghitung jumlah apotik yang memiliki obat**_(Menerima input user, search obat, menampilkan banyak apotik yang memiliki obat x)_<br>
-------------------------------------------------------------------------------
>**16. Jumlah jenis obat**_(dengan iterasi menghitung elemen dalam list child)_<br>
-------------------------------------------------------------------------------
>**17. Jumlah apotik***_(dengan iterasi menghitung elemen dalam list parent)_<br>
-------------------------------------------------------------------------------
## kami mengerjakan sesuai spesifikasi yang diminta dalam google drive dengan tambahan 6 case
>- redundant
>- jumlah apotik
>- jumlah obat
>- jumlah apotik yang memiliki obat x
>- jumlah obat yang dimiliki apotik x
>- is empty
