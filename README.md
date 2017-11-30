## To Do:
1. Patient and doctor profiles to log in.
2. Database.

### Activate Django and Tensorflow environments:
1. Activate Tensorflow (while in `neural` directory): `source activate tensorflow`.
2. Activate Django (while in `web` directory): `source activate django`.

### Installing Python Environment using Anaconda:

#### Tensorflow:
1. `conda create -n tensorflow python=2.7`.
2. `source activate tensorflow`.
3. `sudo pip2 install --ignore-installed --upgrade <TF-URL>`.

#### Django:
1. `conda create -n django python=3.5`.
2. `source activate django`.
3. `sudo pip3 install django`

### Django:
- Create Django project: `django-admin startproject medicall`.
  + File `manage.py` is a command-line utility that allows you to interact with Django in many different ways.
  + File `urls.py` is the URL declarations for Django website.
  + File `wsgi.py` is an entry-point for WSGI-compatible web servers to serve your project.
- Run web-server (while in `web` directory): `python manage.py runserver`.
- To create Django app: `python manage.py startapp website`.
