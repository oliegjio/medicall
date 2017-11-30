from django.conf.urls import url, include

from . import views

urlpatterns = [
    url(r'^$', views.index, name='index'),
    url(r'^signup$', views.signup, name='signup'),
    # url(r'^new-user$', views.new_user, name='new-user')
    url(r'^accounts/', include('django.contrib.auth.urls'))
]
