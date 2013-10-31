Hello World
===========

This is a simple PHP Extension example.

These files could be generated automatically by `php5/ext/ext_skel` command in PHP5 source code.

```
$ cd /path/to/php5/ext
$ ./ext_skel --extname=hello
```

Then make a few edits following tutorial[1].

### Road Map

Branch list is a cool tool for recording the learning road map, as branch name hints every key knowledge and it's order.  

### PHP Source Code

You can get it at [php.net](http://php.net/downloads.php).

But I recommend using the [PHPBrew](https://github.com/c9s/phpbrew) to manage your PHP version.

### Install

```
$ git clone git@git.corp.anjuke.com:liangshan/php-hello
$ cd php-hello
$ /path/to/phpize
$ ./configure
$ make && make install
```

### Example

just run

```
$ php hello.php
```

### Reference

* [1] : http://devzone.zend.com/303/extension-writing-part-i-introduction-to-php-and-zend/
