Hello World
===========

This is a PHP Extension example PHP5.

These files could generate by `php5/ext/ext_skel` command in PHP5 source code.

## PHP Source Code

You can get it at [php.net](http://php.net/downloads.php).

But i recommend using the [PHPBrew](https://github.com/c9s/phpbrew) to manage your PHP version

## Install

```
$ git clone git@git.corp.anjuke.com:liangshan/php-hello
$ cd php-hello
$ /path/to/phpize
$ ./configure
$ make && make install
```

## Example

```php
<?php
print(hello());
?>
```

Or just run

```
$ php hello-world.php
```

## Reference

* http://devzone.zend.com/303/extension-writing-part-i-introduction-to-php-and-zend/