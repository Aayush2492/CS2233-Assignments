#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"
#include "node.h"
#include "queue_by_linked_list.h"
#include "stack_by_linked_list.h"

int main()
{
    linkedList* songList = newList();
    //char str[50]; --------- Works
    //char* str; ------------ Doesn't work
    printf("Enter all songs (as strings and words separated by _), End with \"-1\"\n");
    while(1)
    {
        // IMPORTANT: This str declaration should be inside the loop otherwise songList->firstSong->songName
        //            will keep changing with the new value of str you enter
        char* str = (char*)malloc(sizeof(char)*50);
        fgets(str, sizeof(str), stdin);

        // Removing the trailing new line character from str
        int len = strlen(str);
        if(str[len-1]=='\n')
            str[len-1]='\0';
        
        if(!strcmp(str, "-1"))
        {
            printf("All songs entered!\n");
            break;
        }
        else
        {
            songList->insertSong(songList, str);
        }
    }

    queue* mySongQueue = newQueue();
    printf("Create Playlist, end with \"-1\"\n");
    while(1)
    {
        char* str = (char*)malloc(sizeof(char)*50);
        fgets(str, sizeof(str), stdin);

        // Removing the trailing new line character from str
        int len=strlen(str);
        if(str[len-1]=='\n')
            str[len-1]='\0';

        if(!strcmp(str, "-1"))
        {
            printf("Playlist Ready!\n");
            break;
        }
        else
        {
            bool isSongInLibrary = songList->searchSong(songList, str);
            if(isSongInLibrary)
            {
                mySongQueue->enqueue(mySongQueue, str);
                printf("Found, Enqueued\n");
            }
            else
            {
                printf("Not Found in the song library\n");
            }
        }
        
    }

    stack* recentSongsStack = newStack();
    queue* temporaryQueue = newQueue();
    printf("Play next song, previous songs or end? n/p:k/e\n");
    while(true)
    {
        char* str = (char*)malloc(sizeof(char)*50);
        fgets(str, sizeof(str), stdin);

        // Removing the trailing new line character from str
        int len=strlen(str);
        if(str[len-1]=='\n')
            str[len-1]='\0';

        if(!strcmp(str, "n"))
        {
            if(mySongQueue->numberOfElements != 0)
            {
                char* currentSong = mySongQueue->front(mySongQueue);
                printf("Playing %s\n", currentSong);
                recentSongsStack->push(recentSongsStack, currentSong);
                mySongQueue->dequeue(mySongQueue);
            }
            else
            {
                printf("Your playlist is empty\n");
            }
        }
        else if (str[0]=='p' && str[1]==':')
        {
            // Removing the p and : from str
            str = str + 2;

            unsigned numberOfPreviousSongs = atoi(str);
            for(int i = 1 ; i <= numberOfPreviousSongs ; i++)
            {
                if(recentSongsStack->numberOfElements==0)
                {
                    printf("There aren\'t %u previous songs\n", numberOfPreviousSongs);
                }
                else
                {
                    char* currentSong = recentSongsStack->top(recentSongsStack);
                    printf("Playing %s\n", currentSong);
                    recentSongsStack->pop(recentSongsStack);
                    temporaryQueue->enqueue(temporaryQueue, currentSong);
                }
            }

            //Emptying the temporary queue into the recent songs stack
            unsigned initialSizeOfTempQueue = temporaryQueue->numberOfElements;
            for(int i=1 ; i<=initialSizeOfTempQueue ; i++)
            {
                recentSongsStack->push(recentSongsStack, temporaryQueue->front(temporaryQueue));
                temporaryQueue->dequeue(temporaryQueue);
            }
        }
        else if(!strcmp(str, "e"))
        {
            printf("Bye\n");
            break;
        }
        else
        {
            printf("Please enter a correct choice\n");
        }
        
    }

    return 0;
}