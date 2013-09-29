<?php
$br = (php_sapi_name() == "cli")? "":"<br>";

if(!extension_loaded('hello')) {
    dl('hello.' . PHP_SHLIB_SUFFIX);
}
$module = 'hello';
$functions = get_extension_funcs($module);
echo "Functions available in the test extension:$br\n";
foreach($functions as $func) {
    echo $func."$br\n";
}
echo "$br\n";
if (extension_loaded($module)) {
	echo hello_world();
	echo "\n";
}
?>
