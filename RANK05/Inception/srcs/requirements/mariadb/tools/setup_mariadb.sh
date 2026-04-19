#!/bin/bash

set -e

DB_PWD=$(cat /run/secret/db_password.txt)
DB_ROOT_PWD=$(cat /run/secret/db_root_password.txt)

if [ ! -d "/var/lib/mysql/mysql" ]; then
    mariadb-install-db --user=mysql --datadir=/var/lib/mysql

    mysqld_safe --datadir=/var/lib/mysql & pid="$!"

    until mariadb-admin ping >/dev/null 2>&1; do
        sleep 1
    done

    mariadb -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PWD}';"
    mariadb -uroot -p"${DB_ROOT_PWD}" -e "CREATE DATABASE IF NOT EXISTS \`${DB_NAME}\`;"
    mariadb -uroot -p"${DB_ROOT_PWD}" -e "CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PWD}';"
    mariadb -uroot -p"${DB_ROOT_PWD}" -e "GRANT ALL PRIVILEGES ON \`${DB_NAME}\`.* TO '${DB_USER}'@'%';"
    mariadb -uroot -p"${DB_ROOT_PWD}" -e "FLUSH PRIVILEGES;"

    mariadb-admin -uroot -p"${DB_ROOT_PWD}" shutdown
    wait "$pid" || true
fi

exec mysql --user=mysql
