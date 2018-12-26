<?php 
show_source(__FILE__);
@include_once 'flag.php';
//前端攻城狮跑路了，不过PHP是最好的语言
	$a = $_GET['a'];
	$b = $_GET['b'];
	$good = false;
	if (sha1($a)===sha1($b)) {
		$good = true;
	}
	else die('bypass');
	if ($good && isset($_GET['key'])){
		$message = json_decode($_GET['key']);
		if ($message->key==$key) {
			echo $flag;
		}	
		else die('还差一点就拿到flag了');
	}

?>
