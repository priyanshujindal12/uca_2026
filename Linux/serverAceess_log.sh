#!/bin/bash
if [ ! -f "server_access.log" ]; then
    echo "Error: server_access.log not found!"
    exit 1
fi

sed -i '/^#/d' server_access.log
sed -i 's/HTTP\/1\.0/HTTP\/1.1/g' server_access.log
sed -E -i 's/[0-9]{4}-[0-9]{4}-[0-9]{4}-[0-9]{4}|[0-9]{16}/XXXX-XXXX-XXXX-XXXX/g' server_access.log

echo "Log cleanup completed successfully."