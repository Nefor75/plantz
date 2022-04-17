<?php
 
        $host =     'intui2.mysql.ukraine.com.ua'; 
		$user =     'intui2_app'; 
		$password = '2P-s&6uy7H'; 
		$db_name =  'intui2_app'; 

		$link = mysqli_connect($host, $user, $password, $db_name);

	    //Кодировка (не обязательно)
		//mysqli_query($link, "SET NAMES 'utf8'");

	    $query = "SELECT * FROM plants1";

	    $result = mysqli_query($link, $query);
	
        $row = mysqli_fetch_array($result);
        echo json_encode($row);

?>       