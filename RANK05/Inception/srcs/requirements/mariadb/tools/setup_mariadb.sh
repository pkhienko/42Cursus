#!/bin/bash

DB_PWD=$(cat /run/secrets/db_password)
DB_ROOT_PWD=$(cat /run/secrets/db_root_password)

mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld /val/lib/mysql

if [ ! -d "/var/lib/mysql/mysql" ]; then
    mariadb-install-db --user=mysql --datadir=/var/lib/mysql

    mariadbd &
    pid="$!"

    until mariadb-admin ping --silent; do
        sleep 1
    done

    mariadb -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PWD}';"
    mariadb -uroot -p"${DB_ROOT_PWD}" -e "CREATE DATABASE IF NOT EXISTS \`${DB_NAME}\`;"
    mariadb -uroot -p"${DB_ROOT_PWD}" -e "CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PWD}';"
    mariadb -uroot -p"${DB_ROOT_PWD}" -e "GRANT ALL PRIVILEGES ON \`${DB_NAME}\`.* TO '${DB_USER}'@'%';"
    mariadb -uroot -p"${DB_ROOT_PWD}" -e "FLUSH PRIVILEGES;"

    mariadb-admin -uroot -p"${DB_ROOT_PWD}" shutdown
    wait "$pid"
fi

exec mariadbd
