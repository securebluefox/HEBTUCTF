<html>
<body>
a和b满足以下条件:<br>
($_GET['a']!=$_GET['b'] &&
md5($_GET['a']) == md5($_GET['b']))
<br>
简单的PHP弱类型，找到符合的a和b我就给你flag
<br>
<?php
$flag = "HEBTUCTF{Have_Fun_w1th_Php}";
if($_GET['a']!=$_GET['b'] &&
md5($_GET['a']) == md5($_GET['b']))
{
echo "Flag: " . $flag;
}
?>

</body>
</html>