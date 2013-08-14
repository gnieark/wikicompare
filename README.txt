DESCRIPTION
===========
The wikicompare module allows you to transform your Drupal into a powerful comparison platform with collaborative features.

The module will create three new objects :
-The feature object, which represent the criteria of the comparison. It has :
    -A name
	-A description (with wysiwyg)
	-A parent feature, which means we can build a features tree with as many level as necessary
	-A sequence, to order them
	-A state, so the admins can control if a suggested feature should be published or not
	-A type, which determine the way the feature percent should be computed : either make a weighted average of the children percent, or take the highest percentage among his children
	-The validation guidelines, which give the conditions defining when the feature is considered supported or not
	-The weight, used for the percent computation of the parent feature
	-The powers users, if a user is defined here then he'll have moderation power on this feature and all his feature children
	
-The compared object, which represent the products we want to compare. It has :
    -A name
	-A description (with wysiwyg)
	-A parent compared, which means we can build a compareds tree with as many level as necessary
	-A sequence, to order them
	-A state, so the admins can control if a suggested compared should be published or not
	-The powers users, if a user is defined here then he'll have moderation power on this compared and all his compared children
	
-The implementation object, which represent the support of a criteria in a product. It has :
	-A feature and a compared entityreference fields to link the implementation to the feature and compared which created it
	-A description
	-A boolean indicating if the feature is supported or not by the compared
	-A boolean which can be used by the moderator to protect the implementation. In this case, only a moderator of the feature can modify the supported boolean.
	-A list of the links which proves that the feature is supported or not.
We can't create manually an implementation, they are automatically created when we create a new feature or a new compared.

Each object is managed by Drupal core, which means they are stored in node table. This way, each item has comments, translations and revisions thanks to the revisionning module. Everyone can submit a revision on a new item, but only moderators can publish them.

The main page which is created by the module is the comparative table. When you load this page, it will display :
-The list of the compareds on the first level of the compareds tree.
-A one-column table, which contains the features on the first level of the feature tree.

If you click on a compared, it will display his children. You can select a compared by checking his checkbox, which will add a column on the table with the implementations of this compared, and the corresponding percentage.
Same if you click on a feature, it will display new rows in the table with the feature children and the corresponding implementations. 

Everything is managed by ajax, so there will be no performance problem when the table will have thousands data in database.

Also, note that you can manually select the feature which are important for you, and then click on compute table. The displayed feature will be the one that you selected and the percentage will be recomputed.

You can also modify the table by clicking on "Toogle Fastaction" which will add some ajax items after the compareds/features/implementation. With these items, you can add, edit or remove a node directly in the comparative table. A form will be displayed with a confirm button and the table will be updated after submit.
Note that there is a function which update the whole table each time you make an ajax call. It'll update the table after you make a fastaction, but it'll also do the same when someone else makes a change.

Also note that you can only fastedit a node if you are the only one which has revisions in it. If someone else submits a revision, you'll have to go to the node page to see the comments/revisions before making any change.
This ensures that you can easily fill the table (through fastaction) but if there is a debate you still have to read the opinions of the others.


The second page is the dashboard. Here, you can see all the activity of the wikicompare, which node was modified and by whom, with all the filters you need.
This is a standard Drupal view that we exported, nothing specific here.

The third page is the administration page, only accessible if you have the wikiadmin role. Here you can change the main language of the wikicompare, configure if you can select a parent compared in the table, and flush the wikicompare caches.


OTHER MODULES
=============
wikicompare_profiles :
This module creates a new object, the profiles, which we can select in the comparative table.
These profiles contain a list of features in them. If we check a profile in the comparative table and then compute it, the table will be recomputed with the features of the selected profiles.
This allow us to configure some profile of user, which will then be able to find the best product for them, not only the best product overall.

wikicompare_translation :
This module allows us to manage some translated nodes of the main nodes. These translated nodes will have their own name and description, but not important fields like parent, weight, type etc...
When you go on the comparative table, the items will have the names of the translated node for the user language if they exist.

wikicompare_inherit_compared : 
This module allows a compared to inherit another compared (for example this represent a product which would be a new version of another one). When a compared inherit another one, it'll automatically take the support implementation of the inherited compared, unless we specify the contrary in the implementation.

wikicompare_generate_demo :
This module, which is not for production purpose, allows us to generate demo data to stress test the wikicompare. It also contains some export tools and some predefined demo data on specific themes.


TECHNICAL EXPLANATIONS
======================
In the comparative table, the percent of the implementations are not computed on each visit. The percentage is store in a cache table and computed each time a structural field (type in feature, support in implementation, parent etc...) change.
There is an exception through, when you compute the table with profiles or manual selected features, the percentage are recomputed.

The function which updates the percentage, located in wikicompare_core_functions.inc, is a monstrous recursive function. The reason is the fact it has to update each implementations of parent feature or parent compared, which mean it's a recursive function on two axis. If you like challenge, I suggest you try to read this function, you'll like it.

Drupal, by stocking all items in the node table and the fields in another table, has definitely not the good model to manage such computation. So I created alternate tables, cache_feature, cache_compared and cache_implementation, which holds the data in a better way. Theses tables are updated by functions in the file wikicompare_nodes.inc, these extra db requests are by no mean a problem for performance.
By doing this, I managed to make enough optimization to make the system works. I don't know if there are more possible optimizations possible on the percent computation, but at least now this is not the drupal fault.

My only left concern about performance is the implementation creation. When you try to create a compared when there are 5000 features, you can expect several minutes of computation because it will create the 5000 implementation needed, and then update the table with theses 5000 implementations as argument of the function. Most of the time is taken by the update table function through, not the implementation creation which takes 30seconds, so maybe we have some hope if we can still improve the update function.

Because of this, I consider the current limit of the system start appear with 5000 nodes on one axis. This is enough to start the project, but we'll need to be able to manage millions of feature/compared to be really comfortable. Any audit of the code from a good DBA will be more than welcome.

Finally, I do recommend using postgresql instead of mysql, it's really better for managing such complicated query.


AUTHOR
======
Yannick Buron, Paris, France.