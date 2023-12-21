#!/bin/sh

if [ ! -f "/var/www/html/index.php" ]; then
	wp core download
	wp config create \
		--dbname=${MYSQL_DATABASE} \
		--dbuser=$MYSQL_USER \
		--dbpass=$MYSQL_USER_PASSWORD \
		--dbhost=mariadb:3306
	wp core install \
		--url=http://heson.42.fr \
		--title="heson's blog" \
		--admin_user=$WP_ADMIN \
		--admin_password=$WP_ADMIN_PASSWORD \
		--admin_email=$WP_ADMIN_EMAIL
	wp user create ${WP_USER} ${WP_USER_EMAIL} --role=author --user_pass=${WP_USER_PASSWORD}
fi

exec php-fpm -F