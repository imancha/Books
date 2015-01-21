<?php include_once('connect.inc');
/*
 * customer.inc
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

	function view(){
		echo '<table id="dyntable" class="table table-bordered responsive">
						<thead><tr><th class="head1 text-center"></th><th class="head0 text-center">#</th><th class="head1 text-center">Name</th><th class="head0 text-center">Email</th><th class="head1 text-center">Phone</th><th class="head0 text-center">Company</th><th class="head1 text-center">Address</th><th class="head0 text-center">City</th><th class="head1 text-center">Post Code</th><th class="head0 text-center">State</th><th class="head1 text-center">Country</th></tr></thead>
						<tbody>';
		mysql_open();
		$sql = "SELECT * FROM `Customer`";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_num_rows($res) > 0){
			while($row = mysql_fetch_assoc($res)){
				echo '<tr>
								<td></td>
								<td>'.++$i.'</td>
								<td>'.$row['First Name'].' '.$row['Last Name'].'</td>
								<td>'.$row['Email'].'</td>
								<td>'.$row['Phone'].'</td>
								<td>'.$row['Company'].'</td>
								<td>'.$row['Address'].'</td>
								<td>'.$row['City'].'</td>
								<td>'.$row['Post Code'].'</td>
								<td>'.$row['State'].'</td>
								<td>'.$row['Country'].'</td>
							</tr>';
			}
		}		
		mysql_close();
		echo '	</tbody>
					</table>';
	}
	
	switch($_GET['i']){
		default: view();
	}
?>
