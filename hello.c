/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2013 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: liangshan                                                    |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_hello.h"

ZEND_DECLARE_MODULE_GLOBALS(hello)


/* True global resources - no need for thread safety here */
static int le_hello;

/* {{{ hello_functions[]
 *
 * Every user visible function must have an entry in hello_functions[].
 */
const zend_function_entry hello_functions[] = {
	PHP_FE(hello_world, NULL)
	PHP_FE(hello_long, NULL)
	PHP_FE_END	/* Must be the last line in hello_functions[] */
};
/* }}} */

/* {{{ hello_module_entry
 */
zend_module_entry hello_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"hello",
	hello_functions,
	PHP_MINIT(hello),
	PHP_MSHUTDOWN(hello),
	PHP_RINIT(hello),
	PHP_RSHUTDOWN(hello),
	PHP_MINFO(hello),
#if ZEND_MODULE_API_NO >= 20010901
	"0.0.2",
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_HELLO
ZEND_GET_MODULE(hello)
#endif

/* {{{ PHP_INI
 */
PHP_INI_BEGIN()
    /* test PHP_INI first
    STD_PHP_INI_ENTRY("hello.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_hello_globals, hello_globals)
    STD_PHP_INI_ENTRY("hello.global_string", "Hello World!", PHP_INI_ALL, OnUpdateString, global_string, zend_hello_globals, hello_globals)
	*/
	PHP_INI_ENTRY("hello.greeting", "Hello World", PHP_INI_ALL, NULL)
PHP_INI_END()
/* }}} */

/* {{{ php_hello_init_globals
 */
static void php_hello_init_globals(zend_hello_globals *hello_globals)
{

}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(hello)
{
	ZEND_INIT_MODULE_GLOBALS(hello, php_hello_init_globals, NULL);
	REGISTER_INI_ENTRIES();
	
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(hello)
{
	UNREGISTER_INI_ENTRIES();
	
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(hello)
{
	HELLO_G(counter) = 0;
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(hello)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(hello)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "hello support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ return 'hello world', only for example. 
 */
PHP_FUNCTION(hello_world)
{
	RETURN_STRING(INI_STR("hello.greeting"), 1);
}
/* }}} */

/* {{{ return COUNTER++. 
 */
PHP_FUNCTION(hello_long)
{
    HELLO_G(counter)++;
    RETURN_LONG(HELLO_G(counter));
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
