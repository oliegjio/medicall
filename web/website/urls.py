from django.conf.urls import url, include

from . import views

urlpatterns = [
    url(r'^$', views.index, name='index'),
    url(r'^accounts/', include('django.contrib.auth.urls')),
    url(r'^signup$', views.signup, name='signup'),
    url(r'^user/(?P<id>[0-9]+)', views.user, name='user')
]
