import logging
from gym.envs.registration import register

logger = logging.getLogger(__name__)

register(
    id='Doodle-v0',
    entry_point='gym_doodle.envs:DoodleEnv'
)
