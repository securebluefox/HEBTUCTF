<html>
<title>
	签到题
</title>
<body>
	<div><h1>大家吼，我系签到题</h1></div>
	<div>flag的格式为：HEBTUCTF{XXXX}</div>
	<div>（若题目指出flag格式则按题目为准）</div>
	<div>现在去获得flag吧</div>

	<form method="POST">
		<p><input type="text" name="key" maxlength="10"/></p>
		<p><input type="hidden" name="qiandao" value="0"/></p>
  		<p><input type="submit" value="提交" /></p>
	</form>
<?php  
	if(!empty($_POST)){
	$key=$_POST['key'];
	$qiandao=$_POST['qiandao'];
	if ($key==="HEBTUCTF2018") {
		if ($qiandao!="0") {
			echo "HEBTUCTF{Qi4n_Da0_cH3n9_g0n9}";
		}
		else{
			echo "小火汁你没签到啊";
		}
	}
	else{
		echo "<script>alert('小火汁提交HEBTUCTF2018啊')</script>";
	}
}
?>
</body>
</html>
