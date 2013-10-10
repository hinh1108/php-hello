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
    echo "execute hello_world():\n";
    echo hello_world() . "\n";
    echo "we can change return value by ini_set('hello.greeting', 'World Hello'):\n";
    ini_set('hello.greeting', 'World Hello');
    echo hello_world() . "\n";

    echo "execute hello_long() for 10 times, counter plus 1 every time:\n";
    for ($i=0; $i<10; $i++) {
        echo hello_long() . " ";
    }
    echo "\n";
    echo "now we change direction by ini_set('hello.direction', 0), counter minus 1 every time:\n";
    ini_set('hello.direction', 0);
    for ($i=0; $i<10; $i++) {
        echo hello_long() . " ";
    }
    echo "\n";

    echo "execute hello_greetme('php'):\n";
    hello_greetme('php');
    echo "\n";
}
?>
