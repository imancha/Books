/*
 * script.js
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

var xmlhttp;
function GetXmlHttpObject(){
	// code for IE7+, Firefox, Chrome, Opera, Safari
	if (window.XMLHttpRequest){	return new XMLHttpRequest(); }
	// code for IE6, IE5
	if (window.ActiveXObject){ return new ActiveXObject("Microsoft.XMLHTTP"); }
	return null;
}
function displayBook(){ if (xmlhttp.readyState==4){ document.getElementById('displayBook').innerHTML=xmlhttp.responseText; } }
function showBook(id){
	xmlhttp=GetXmlHttpObject();
	if (xmlhttp==null){ alert ("Your browser does not support AJAX!"); return; }	
	xmlhttp.onreadystatechange=displayBook;
	xmlhttp.open("GET",("./ajax/getBook.php?id="+id),true);
	xmlhttp.send(null);
}
