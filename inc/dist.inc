<?php
/*
 * dist.inc
 * 
 * Copyright 2015 Imancha <imancha_266@ymail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

	if($_SESSION['region'] == 1){
		$O0 = 'Beranda';
		$O1 = 'Kategori';
		$O2 = 'Halaman';
		$O3 = 'Bantuan';
		$O4 = 'Tentang';
		$O5 = 'Daftar Keinginan';
		$O6 = 'Keranjang Saya';
		$O7 = 'Checkout';
		$O8 = 'Produk';
		$O9 = 'Category Grid';
		$O10 = 'Category List';
		$O11 = 'Kontak';
		$O12 = 'Lihat Keranjang';
		$O13 = 'Spesial';
		$O14 = 'Lihat';
		$O15 = 'Tambah ke Keranjang';
		$O16 = 'Best Seller';
		$O17 = '<p style="word-spacing:2px; font-size:larger;"><strong>Imancha Online Shop</strong> adalah sebuah toko buku online yang menjual buku-buku dari berbagai macam kategori. Temukan buku-buku yang berkualitas yang dijual dengan harga diskon. Gratis Pengiriman dan Cash on Delivery di seluruh dunia di lebih dari 100 kota. Hadiah kejutan dengan nilai 30% pada pesanan lebih dari Rp. 700.000. Sale Upto 50% pada semua buku. Harga Nyaman & terjangkau untuk Anda. 100% Jaminan Uang Kembali *. Kami mendukung segala sesuatu yang kami jual dengan dukungan 24/7.</p><p style="word-spacing:2px; font-size:larger;">Saat ini, toko kami tersedia di Indonesia dan Amerika Serikat. Tetapi toko online kami dapat diakses dari seluruh dunia yang membuat belanja menjadi semakin mudah, kapanpun dan dimanapun.</p>';
		$O18 = 'Keranjang';
		$O19 = 'Langkah';
		$O20 = 'ALAMAT PENGIRIMAN';
		$O21 = 'Your Personal Details';
		$O22 = '*harus diisi';
		$O23 = 'Nama Depan*';
		$O24 = 'Nama Belakang*';
		$O25 = 'Email*';
		$O26 = 'Phone*';
		$O27 = 'Alamat*';
		$O28 = 'Perusahaan';
		$O29 = 'Alamat*';
		$O30 = 'Kota*';
		$O31 = 'Kode Post*';
		$O32 = 'Provinsi*';
		$O33 = 'Negara*';
		$O34 = 'Lanjut';
		$O35 = 'Ubah';
		$O36 = 'METODE PENGIRIMAN';
		$O37 = 'Silahkan pilih metode pengiriman yang digunakan pada pemesanan ini.';
		$O38 = 'METODE PEMBAYARAN';
		$O39 = 'Silahakan pilih metode pembayaran yang digunakan pada pemesanan ini.';
		$O40 = 'Komentar/pesan';
		$O41 = 'Konfirmasi Pesanan';
		$O42 = 'Silahkan konfirmasi pesanan anda.';
		$O43 = 'Batal';
		$O44 = 'Terima kasih telah berbelanja pada Imancha Online Shop. Kami akan segera memproses pesanan anda.';
		$O45 = 'Menampilkan';
		$O46 = 'dari';
		$O47 = 'produk';
		$O48 = 'per halaman';
		$O49 = 'Lihat Semua';
		$O50 = 'Nama';
		$O51 = 'Harga';
		$O52 = 'Rendah-Tinggi';
		$O53 = 'Tinggi-Rendah';
		$O54 = 'Penerbit';
		$O55 = 'Terbaru';
		$O56 = 'Produk ini mempunyai';
		$O57 = 'review';
		$O58 = 'selengkapnya';
		$O59 = 'Tambah ke Keinginan';
		$O60 = 'Pengarang';
		$O61 = 'Penerbit';
		$O62 = 'Halaman';
		$O63 = 'Tahun';
		$O64 = 'Bahasa';
		$O65 = 'Ketersediaan';
		$O66 = 'dalam Stock';
		$O67 = 'Deskripsi';
		$O68 = 'Review';
		$O69 = 'Tags';
		$O70 = 'mempunyai';
		$O71 = 'Tambahkan Review';
		$O72 = 'Tulis review';
		$O73 = 'id-ID';
	}else{
		$O0 = 'Home';
		$O1 = 'Categories';
		$O2 = 'Pages';
		$O3 = 'Help';
		$O4 = 'About';
		$O5 = 'Wishlist';
		$O6 = 'My Cart';
		$O7 = 'Checkout';
		$O8 = 'Product';
		$O9 = 'Category Grid';
		$O10 = 'Category List';
		$O11 = 'Contact';
		$O12 = 'View Cart';
		$O13 = 'Specials';
		$O14 = 'View';
		$O15 = 'Add to Cart';
		$O16 = 'Best Seller';
		$O17 = '<p style="word-spacing:2px; font-size:larger;"><strong>Imancha Online Shop</strong> is an online book store that sell books from various categories. Discover quality books for sale at discounted prices. Free Shipping and Cash on Delivery all over in world over $100. Surprise Gift with value $50 on orders over $700. Summer Sale Upto 50% off on all books. Convenient & affordable prices for you. 100% Money Back Guarantee*. We support everything we sell with 24/7 support.</p><p style="word-spacing:2px; font-size:larger;">Currently, our store are available in <strong>Indonesia</strong> and <strong>United States</strong>. But our online store can be accessed from all over the world that made shopping very easy, everytime and everywhere.</p>';
		$O18 = 'Cart';
		$O19 = 'Steps';
		$O20 = 'SHIPPING ADDRESS';
		$O21 = 'Your Personal Details';
		$O22 = '*required';
		$O23 = 'First Name*';
		$O24 = 'Last Name*';
		$O25 = 'Email*';
		$O26 = 'Phone*';
		$O27 = 'Address*';
		$O28 = 'Company';
		$O29 = 'Address*';
		$O30 = 'City*';
		$O31 = 'Post Code*';
		$O32 = 'State*';
		$O33 = 'Country*';
		$O34 = 'Continue';
		$O35 = 'Update';
		$O36 = 'SHIPPING METHOD';
		$O37 = 'Please select the preferred shipping method to use on this order.';
		$O38 = 'PAYMENT METHOD';
		$O39 = 'Please select the preferred Payment method to use on this order.';
		$O40 = 'Comments/messsage';
		$O41 = 'Confirm Order';
		$O42 = 'Please confirm your order.';
		$O43 = 'Cancel';
		$O44 = 'Thank you for shopping at Imancha Online Shop. We will process your order immediately.';
		$O45 = 'Showing';
		$O46 = 'of';
		$O47 = 'products';
		$O48 = 'per page';
		$O49 = 'Show All';
		$O50 = 'Name';
		$O51 = 'Price';
		$O52 = 'Low-High';
		$O53 = 'High-Low';
		$O54 = 'Publisher';
		$O55 = 'Recent';
		$O56 = 'This product has';
		$O57 = 'review(s)';
		$O58 = 'read more';
		$O59 = 'Add to Wishlist';
		$O60 = 'Author';
		$O61 = 'Publisher';
		$O62 = 'Pages';
		$O63 = 'Year';
		$O64 = 'Language';
		$O65 = 'Availability';
		$O66 = 'in Stock';
		$O67 = 'Description';
		$O68 = 'Reviews';
		$O69 = 'Tags';
		$O70 = 'has';
		$O71 = 'Add Review';
		$O72 = 'Write a review';
		$O73 = 'en-US';
	}
?>
