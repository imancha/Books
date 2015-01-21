<?php include_once('connect.inc');
/*
 * catalogue.inc
 *
 * Copyright 2014 Imancha <imancha_266@ymail.com>
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
		mysql_open();
		$sql = "SELECT * FROM `Book` ORDER BY `Title` ASC";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_num_rows($res) > 0){
			echo '<table class="table table-bordered responsive">
							<thead>
								<tr>
									<th class="head0"></th>
									<th class="head1">#</th>
									<th class="head0">Title</th>
									<th class="head1">Subtitle</th>									
									<th class="head1">ISBN</th>
									<th class="head0">Page</th>
									<th class="head1">Year</th>
									<th class="head0">Publisher</th>
									<th class="head1">Language</th>
									<th class="head0"><i class="iconfa-external-link"></i></th>
									<th class="head1"><i class="iconfa-edit"></i></th>
									<th class="head0"><i class="iconfa-trash"></i></th>
								</tr>
							</thead>
							<tbody>';
			while($row = mysql_fetch_assoc($res)){
				echo '<tr>
								<td></td>
								<td>'.(++$i).'</td>
								<td>'.$row['Title'].'</td>								
								<td>'.$row['SubTitle'].'</td>
								<td>'.$row['ISBN'].'</td>
								<td>'.$row['Page'].'</td>
								<td>'.$row['Year'].'</td>
								<td>'.$row['Publisher'].'</td>
								<td>'.$row['Language'].'</td>
								<td><button class="btn btn-transparent btn-success" data-target="#view'.$i.'" data-toggle="modal"><i class="iconfa-external-link"></i></button></td>
								<td><button class="btn btn-transparent btn-warning" data-target="#edit'.$i.'" data-toggle="modal"><i class="iconfa-edit"></i></button></td>								
								<td><button class="btn btn-transparent btn-danger"><i class="iconfa-trash"></i></button></td>
							</tr>
							<div aria-hidden="false" aria-labelledby="myModalLabel" role="dialog" tabindex="-1" class="modal hide fade in" id="view'.$i.'">
								<div class="modal-header">
									<button aria-hidden="true" data-dismiss="modal" class="close" type="button">&times;</button>
									<h3 id="myModalLabel">'.$row['Title'].' <div><small>'.$row['SubTitle'].'</small></div></h3>
								</div>
								<div class="modal-body">									
									<div class="desc">'.$row['Description'].'</div>
								</div>								
							</div><!--#myModal-->';
			}
			echo '	</tbody>
						</table>';
		}
		mysql_close();
	}

	view();
?>
