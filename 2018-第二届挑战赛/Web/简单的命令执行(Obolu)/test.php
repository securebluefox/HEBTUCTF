<html>
<head>
嘿嘿嘿<br>
</head>
<body>
	源码如下：<br>
	preg_replace("/123(.+?)123/ies", 'text("\\1")', $h)<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>hint1:flag在PHPINFO<br>
<?php 
$h = $_POST["h"];
function text($str)
{
	echo '123';
}
echo preg_replace("/123(.+?)123/ies", 'text("\\1")', $h);
?>
</body>
<!--hint2:Try POST?-->
</html>