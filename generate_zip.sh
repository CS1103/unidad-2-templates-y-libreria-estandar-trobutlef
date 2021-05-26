#!/usr/bin/env bash

project_name=task_7
source_code='exercises.h'
rm -f ${project_name}.zip
zip -r -S ${project_name} ${source_code}