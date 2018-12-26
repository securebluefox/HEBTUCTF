<header>
	<meta charset="utf-8">
</header>
<body>
	<h1>在下宇宙第一大黑阔</h1>
	<h3>在线打击，指哪打哪</h3>
	<h3>输入你的攻击目标</h3>
	<form method="POST">
		<input type="text" name="ip"/>
		<input type="submit" value="提交" />
	</form>
<?php 
	if(isset($_POST['ip'])){
		$ip =(string)$_POST['ip'];
		$ip =str_replace(">","^_^",$ip); #防重定向和反弹shell
		$ip =str_replace("tar","0_0",$ip); #防止tar打包
		exec("ping -c 1 ".$ip);
		die('小火汁，你看看他还在线不?');
	}

?>
</body>